#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const int INF = 2e9;
int N, A[MN], B[MN], P[MN], S[MN], D[MN], E[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int j=1; j<=N; j++) cin >> B[j];
  sort(A+1, A+N+1);
  sort(B+1, B+N+1);

  for (int i=1; i<=N; i++) P[i] = max(P[i-1], abs(A[i] - B[i]));
  for (int i=N; i>=1; i--) S[i] = max(S[i+1], abs(A[i] - B[i]));

  for (int i=1; i<=N-1; i++) {
    D[i] = min(P[i], max(D[i-1], abs(A[i] - B[i+1])));
  }
  for (int i=N; i>=2; i--) {
    E[i] = min(S[i], max(E[i+1], abs(A[i] - B[i-1])));
  }

  int mn = S[2], opt = 1;
  for (int i=1; i<=N-1; i++) {
    if (max(D[i], S[i+2]) < mn) { opt = i+1; mn = max(D[i], S[i+2]); }
  }
  for (int i=2; i<=N; i++) {
    if (max(E[i], P[i-2]) < mn) { opt = i-1; mn = max(E[i], P[i-2]); }
  }

  cout << A[opt] << endl;

  ////////////////////////////////
  return 0;
}
