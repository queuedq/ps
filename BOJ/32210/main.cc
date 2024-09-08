#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
const int MP = 1e6+5;
const int INF = 1e9;
int N, Q;

struct Line {
  int p, l;
  bool operator<(const Line &L) const { return l < L.l; }
};
Line L[MN];

int D[MN][MP]; // use L[1..i], cost j, max len

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=N; i++) cin >> L[i].p >> L[i].l;
  sort(L+1, L+N+1);

  fill_n(D[0], MP, -INF);
  D[0][0] = 0;

  for (int i=1; i<=N; i++) {
    auto [p, l] = L[i];
    for (int j=0; j<MP; j++) {
      D[i][j] = D[i-1][j];
      if (j-p >= 0) D[i][j] = max(D[i][j], D[i-1][j-p] + l);
    }
  }

  for (int q=0; q<Q; q++) {
    int p, l; cin >> p >> l;
    bool ok = 0;
    for (int i=1; i<=N; i++) {
      ok |= (L[i].l <= l && l <= D[i][p]);
    }
    cout << (ok ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
