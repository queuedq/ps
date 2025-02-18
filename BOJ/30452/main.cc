#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, K, A[MN][MN], S[MN][MN], D[MN][MN];
vector<lld> delta;

void dp(int i) {
  for (int x=1; x<=N; x++) {
    for (int k=0; k<=x/3; k++) {
      D[x][k] = D[x-1][k];
      if (x >= 3 && k >= 1) D[x][k] = max(D[x][k], D[x-3][k-1] + S[i][x]);
    }
  }

  for (int k=1; k<=N/3; k++) delta.push_back({D[N][k] - D[N][k-1]});
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) cin >> A[i][j];
    for (int j=3; j<=N; j++) S[i][j] = A[i][j-2] + A[i][j-1] + A[i][j];
  }

  for (int i=1; i<=N; i++) dp(i);

  lld ans = 0;
  sort(delta.rbegin(), delta.rend());
  for (int i=0; i<min(K, (lld)sz(delta)); i++) ans += delta[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
