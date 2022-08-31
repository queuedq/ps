#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, K, X[MN], max_X;
vector<int> adj[MN];

lld dfs(int u, int p, lld s, int &cnt) {
  vector<lld> costs;
  lld tot = X[u];
  for (auto v: adj[u]) {
    if (v == p) continue;
    lld c = dfs(v, u, s, cnt);
    costs.push_back(c);
    tot += c;
  }
  sort(all(costs));
  while (tot > s) {
    tot -= costs.back();
    costs.pop_back();
    cnt++;
  }
  return tot;
}

bool check(lld s) {
  int cnt = 0;
  dfs(1, 0, s, cnt);
  return cnt <= K;
}

void solve() {
  cin >> N >> K;
  max_X = 0;
  for (int i=1; i<=N; i++) {
    cin >> X[i];
    max_X = max(max_X, X[i]);
  }
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  lld l = max_X-1, r = 1e15;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }

  cout << r << endl;
}

void reset() {
  for (int i=1; i<=N; i++) adj[i].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    solve();
    reset();
  }

  ////////////////////////////////
  return 0;
}
