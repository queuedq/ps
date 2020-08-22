#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2005;
int N, K, M;
int D[MAXN][MAXN];

void solve(int test) {
  cin >> N >> K >> M;

  for (int i=1; i<=N; i++) {
    fill(D[i], D[i]+N+1, MAXN);
    D[i][i] = 0;
  }

  for (int j=1; j<=K; j++) {
    int a, b; cin >> a >> b;

    for (int i=1; i<=N; i++) {
      int A = D[i][a], B = D[i][b];
      D[i][a] = min(A+1, B);
      D[i][b] = min(A, B+1);
    }
  }

  int ans = 0;
  for (int i=1; i<=M; i++) {
    int s, e; cin >> s >> e;
    if (D[s][e] >= MAXN) ans -= 1;
    else ans += D[s][e];
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
