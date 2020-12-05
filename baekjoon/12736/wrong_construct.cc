#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
lld N, M, P[MAXN], C[MAXN], D[MAXN];
vector<int> adj[MAXN];
pll R[MAXN];

pll dfs(int u, lld &ans) {
  if (adj[u].size() == 0) return R[u] = {C[u], C[u]};

  vector<lld> lines;
  for (auto v: adj[u]) {
    auto [a, b] = dfs(v, ans);
    ans -= (b - a);
    lines.push_back(a);
    lines.push_back(b);
  }
  sort(lines.begin(), lines.end());
  lld l = lines[lines.size()/2-1];
  lld r = lines[lines.size()/2];
  for (auto x: lines) ans += abs(x - l);

  return R[u] = {C[u]+l, C[u]+r};
}

void dfs2(int u, lld len) {
  auto [a, b] = R[u];
  if (len < a) D[u] = C[u]-(a-len);
  else if (len > b) D[u] = C[u]+(len-b);
  else D[u] = C[u];
  for (auto v: adj[u]) {
    dfs2(v, len-D[u]);
  }
}

set<lld> lens;

void dfs3(int u, lld len) {
  len += D[u];
  if (adj[u].size() == 0) lens.insert(len);
  for (auto v: adj[u]) {
    dfs3(v, len);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=2; i<=N+M; i++) {
    cin >> P[i] >> C[i];
    adj[P[i]].push_back(i);
  }

  lld ans = 0;
  auto [a, b] = dfs(1, ans);

  assert(ans % 2 == 0);
  cout << ans / 2 << endl;

  dfs2(1, a);

  ans = 0;
  for (int i=2; i<=N+M; i++) {
    ans += abs(C[i] - D[i]);
  }
  cout << ans << endl;

  dfs3(1, 0);

  for (auto s: lens) {
    cout << s << " ";
  } cout << endl;

  for (int i=2; i<=N+M; i++) {
    cout << i << " " << C[i] << " " << D[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
