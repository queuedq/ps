#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, M, deg[MN], vst[MN];
set<int> adj[MN];
map<pii, int> chord;
vector<int> ans;

void get_chord(int x, int y) {
  if (chord.count({x, y}) == 0) { ans.push_back(x); return; }
  int u = chord[{x, y}];
  get_chord(x, u);
  get_chord(u, y);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  M += N;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  deque<int> Q;
  for (int u=1; u<=N; u++) {
    if (sz(adj[u]) == 2) Q.push_back(u);
  }

  for (int cnt=N; cnt>3;) { // repeat until a triangle is left
    int u = Q.front(); Q.pop_front();
    if (vst[u]) continue;
    vst[u] = 1; cnt--;

    auto it = adj[u].begin();
    int x = *it, y = *next(it);
    chord[{x, y}] = chord[{y, x}] = u;

    adj[x].erase(u); adj[y].erase(u);
    adj[x].insert(y); adj[y].insert(x);
    if (sz(adj[x]) == 2) Q.push_back(x);
    if (sz(adj[y]) == 2) Q.push_back(y);
  }

  vector<int> tri;
  for (int u=1; u<=N; u++) if (!vst[u]) tri.push_back(u);
  get_chord(tri[0], tri[1]);
  get_chord(tri[1], tri[2]);
  get_chord(tri[2], tri[0]);

  int offset = find(all(ans), 1) - ans.begin();
  if (ans[(offset+1) % N] < ans[(offset+N-1) % N]) {
    for (int i=0; i<N; i++) cout << ans[(offset+i) % N] << " ";
  } else {
    for (int i=0; i<N; i++) cout << ans[(offset+N-i) % N] << " ";
  }

  ////////////////////////////////
  return 0;
}
