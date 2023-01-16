#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
const int INF = 1e9+5;

struct DSU {
  int par[ST], siz[ST], cnt[ST];
  vector<int> stk; // y

  DSU(int N) {
    for (int i=1; i<=N; i++) par[i] = i, siz[i] = 1, cnt[i] = 0;
  }

  int find(int x) { return par[x] == x ? x : find(par[x]); }

  bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return 0;
    if (siz[x] < siz[y]) swap(x, y);
    stk.push_back(y);
    par[y] = x;
    siz[x] += siz[y];
    cnt[x] += cnt[y];
    return 1;
  }

  void rollback() {
    int y = stk.back(); stk.pop_back();
    int x = par[y];
    siz[x] -= siz[y];
    cnt[x] -= cnt[y];
    par[y] = y;
  }

  int get_cnt(int x) { return cnt[find(x)]; }
};

struct Edge {
  int u, v, k;
  bool operator <(const Edge &e) const { return k < e.k; }
};

int N, M, P, Q, p[ST];
Edge edg[ST];
int opt[ST]; // graph [l, x] becomes connected at x = opt[l]

void dnc(int l, int r, DSU &dsu) {
  if (l+1 >= r) return;
  int m = (l+r)/2;

  // assume we have edges [r, opt[l]) in dsu
  // extend left to m
  int op1 = 0, op2 = 0;
  for (int i=m; i<r && i<opt[l]; i++)
    op1 += dsu.merge(edg[i].u, edg[i].v);

  // find opt[m]
  opt[m] = max(m, opt[l]);
  while (opt[m] <= M) {
    op2 += dsu.merge(edg[opt[m]].u, edg[opt[m]].v);
    if (dsu.get_cnt(edg[opt[m]].u) == P) break;
    opt[m]++;
  }

  // left
  while (op2) dsu.rollback(), op2--;

  dnc(l, m, dsu);

  // right
  while (op1) dsu.rollback(), op1--;
  for (int i=max(r, opt[l]); i<opt[m]; i++)
    op2 += dsu.merge(edg[i].u, edg[i].v);

  dnc(m, r, dsu);

  while (op2) dsu.rollback(), op2--;
}

bool check(int t) {
  vector<pii> E;
  for (int i=1; i<=M; i++) {
    E.push_back({edg[i].k, 0});
    E.push_back({edg[i].k + t, 1});
  }
  sort(all(E));

  lld num = 0;
  int l = 1, r = 0;
  for (auto [k, typ]: E) {
    if (typ == 0) r++;
    else l++;
    if (opt[l] <= r) num++;
  }

  // cout << t << " " << num << endl;
  return num >= Q;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> P >> Q;
  for (int i=1; i<=P; i++) cin >> p[i];
  for (int i=1; i<=M; i++) {
    int u, v, k; cin >> u >> v >> k;
    edg[i] = {u, v, k};
  }
  sort(edg+1, edg+M+1);

  // get opt
  DSU dsu(N);
  for (int i=1; i<=P; i++) dsu.cnt[p[i]]++;

  opt[0] = 1;
  opt[M+1] = M+1;
  dnc(0, M+1, dsu);
  
  // for (int i=1; i<=M; i++) cout << opt[i] << endl;

  // parametric
  int l = -1, r = INF;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }

  if (r < INF) cout << r << endl;
  else cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
