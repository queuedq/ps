#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10'005;
int n, m;
unordered_map<string, int> id;
int num;
vector<pii> adj[MAXN];
bool vst[2][MAXN];

void dfs_is(int u) {
  if (vst[1][u]) return;
  vst[1][u] = true;
  for (auto [v, vr]: adj[u]) {
    if (!vr) continue;
    dfs_is(v);
  }
}

void dfs_has(int u, int h) {
  if (vst[h][u]) return;
  vst[h][u] = true;
  for (auto [v, vr]: adj[u]) {
    dfs_has(v, h|!vr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    string A, R, B; cin >> A >> R >> B;
    if (id.count(A) == 0) id[A] = num++;
    if (id.count(B) == 0) id[B] = num++;
    bool r = R == "is-a";
    adj[id[A]].push_back({id[B], r});
  }

  for (int i=1; i<=m; i++) {
    fill(vst[0], vst[0]+num, false);
    fill(vst[1], vst[1]+num, false);
    string A, R, B; cin >> A >> R >> B;

    if (R == "is-a") dfs_is(id[A]);
    else dfs_has(id[A], 0);

    bool ans = vst[1][id[B]];

    cout << "Query " << i << ": ";
    cout << (ans ? "true" : "false") << endl;
  }

  ////////////////////////////////
  return 0;
}
