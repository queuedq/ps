#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, M, par[MN];
vector<int> adj[MN];

struct Train { // train or rail
  int id, p; // train info
  int len; // +: remaining train, -: longest rail
  bool operator<(const Train &T) const { return len < T.len; }
};

vector<Train> station[MN];
pii ans[MN];

Train dfs(int u, int p) {
  par[u] = p;

  auto &TS = station[u];
  TS.push_back({0, u, 0});
  for (auto v: adj[u]) {
    if (v == p) continue;
    Train T = dfs(v, u);
    if (--T.len == 0) ans[T.id] = {T.p, u}; // handle train length 0
    else TS.push_back(T);
  }

  sort(all(TS));

  // match excluding longest train
  int L = sz(TS);
  int ex = L-1; // excluded train or rail
  for (int i=0; i<L-1; i++) {
    if (TS[i].len + TS[L-2-i].len > 0) cout << "NO" << endl, exit(0);
  }

  // shift excluded train or rail
  while (--ex >= 0) {
    int k = L-1-ex;
    if (k <= ex) {
      if (TS[k-1].len + TS[ex+1].len > 0) break;
    } else {
      if (TS[ex+1].len + TS[k].len > 0) break;
    }
  }
  ex++;

  // actually do match
  Train ret = TS[ex];
  TS.erase(TS.begin() + ex);
  L--;
  for (int i=0, j=L-1; i<j; i++, j--) {
    Train &R = TS[i], &T = TS[j];
    if (T.id) {
      for (; T.len+R.len < 0; R.len++) R.p = par[R.p];
      ans[T.id] = {T.p, R.p};
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> M;
  for (int i=1; i<=M; i++) {
    int p, l; cin >> p >> l;
    station[p].push_back({i, p, l});
  }

  Train T = dfs(1, 0);

  if (T.len > 0) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i=1; i<=M; i++) {
      auto [p, q] = ans[i];
      cout << p << " " << q << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
