#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
using vi = vector<int>;
using vvi = vector<vector<int>>;

vvi vec(int N, int M) { return vvi(N, vi(M)); }

vvi rotate(int N, int M, vvi &A) {
  vvi B(M, vi(N));
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      B[j][N-i-1] = A[i][j];
  return B;
}

int solve(int N, int M, int K, vvi A) {
  vvi S = vec(N+1, M+1); // prefix sum
  vvi L = vec(N+1, M+1); // max in top left
  vvi R = vec(N+1, M+1); // max in top right
  vi row = vi(N+1); // max in row
  vvi D = vec(N+1, N+1); // max in y range [l, r)

  for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
      S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i-1][j-1];

  auto square = [&](int i, int j) {
    return S[i][j] - S[i-K][j] - S[i][j-K] + S[i-K][j-K];
  };

  for (int i=K; i<=N; i++) {
    for (int j=K; j<=M; j++)
      L[i][j] = max({L[i-1][j], L[i][j-1], square(i, j)});
    for (int j=M-K; j>=0; j--)
      R[i][j] = max({R[i-1][j], R[i][j+1], square(i, j+K)});
  }

  for (int i=K; i<=N; i++)
    for (int j=K; j<=M; j++)
      row[i] = max(row[i], square(i, j));

  for (int i=0; i<=N-K; i++)
    for (int j=i+K; j<=N; j++)
      D[i][j] = max(D[i][j-1], row[j]);

  int ans = 0;
  for (int i=K; i<=N-K; i++) {
    for (int j=K; j<=M-K; j++)
      ans = max(ans, L[i][j] + R[i][j] + D[i][N]);
    for (int j=i+K; j<=N-K; j++)
      ans = max(ans, D[0][i] + D[i][j] + D[j][N]);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N, M, K;
  cin >> N >> M >> K;

  vvi A = vvi(N, vi(M));
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      cin >> A[i][j];

  int ans = 0;
  for (int d=0; d<4; d++) {
    ans = max(ans, solve(N, M, K, A));
    A = rotate(N, M, A);
    swap(N, M);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
