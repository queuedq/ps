#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 10005;
const int MM = 105;
int N, M, D[MM][MN];
struct Shop {
  int s, p, o;
  bool operator <(const Shop S) const { return p < S.p; }
};
Shop A[MM];

void solve() {
  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    cin >> A[i].s >> A[i].p >> A[i].o;
  }
  sort(A+1, A+M+1);

  fill(D[0], D[0]+N+1, INF);
  D[0][0] = 0;

  for (int i=1; i<=M; i++) {
    for (int j=0; j<=N; j++) D[i][j] = D[i-1][j];
    for (int j=0; j<=N; j++) {
      int cnt = min(A[i].s, N-j);
      int price = A[i].p * cnt + A[i].o;
      D[i][j+cnt] = min(D[i][j+cnt], D[i-1][j] + price);
    }
  }

  cout << D[M][N] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve();

  return 0;
}
