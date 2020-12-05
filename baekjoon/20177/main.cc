#pragma OPTIMIZE("O3")
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld INF = 1e15;
const int MN = 2005;
const int MQ = 2e5+5;

lld n, m, A[MN], bit[MN][MN], ans[MQ];

struct Query {
  lld i, s, e, u;
  bool operator <(const Query &q) const { return u < q.u; }
} Q[MQ];

struct Sum {
  lld s, i, j;
  bool operator <(const Sum &c) const { return s < c.s; }
};
vector<Sum> S;

void update(int i, int j, lld s) {
  for (int x=i; x<=n; x += x&-x) {
    for (int y=j; y<=n; y += y&-y) {
      bit[x][y] = max(bit[x][y], s);
    }
  }
}

lld query(int i, int j) {
  lld s = -INF;
  for (int x=i; x>0; x -= x&-x) {
    for (int y=j; y>0; y -= y&-y) {
      s = max(s, bit[x][y]);
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i=1; i<=n; i++) cin >> A[i];
  for (int i=1; i<=m; i++) {
    lld s, e, u; cin >> s >> e >> u;
    Q[i] = {i, s, e, u};
  }
  sort(Q+1, Q+m+1);

  for (int i=1; i<=n; i++) {
    lld s = 0;
    for (int j=i; j<=n; j++) {
      s += A[j];
      S.push_back({s, i, j});
    }
  }
  sort(S.begin(), S.end());

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) bit[i][j] = -INF;
  }

  int j = 0;
  for (int i=1; i<=m; i++) {
    while (j < S.size() && S[j].s <= Q[i].u) {
      update(n - S[j].i + 1, S[j].j, S[j].s);
      j++;
    }
    ans[Q[i].i] = query(n - Q[i].s + 1, Q[i].e);
  }

  for (int i=1; i<=m; i++) {
    if (ans[i] == -INF) cout << "NONE" << endl;
    else cout << ans[i] << endl;
  }

  return 0;
}
