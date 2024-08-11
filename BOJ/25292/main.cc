#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;

struct Point { lld x, y; };
lld dist(Point A, Point B) { return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y); }

int N;
Point P[MN], Q[MN], J;
deque<int> adj[MN];
int S[MN], T[MN], dst[MN];

bool bfs() {
  queue<pii> Q;
  fill_n(dst+1, N, -1);
  for (int u=1; u<=N; u++) if (S[u] == -1) Q.push({u, dst[u] = 0});

  bool ok = 0;
  while (!Q.empty()) {
    auto [u, d] = Q.front(); Q.pop();
    for (auto v: adj[u]) {
      if (T[v] == -1) ok = 1;
      else if (dst[T[v]] == -1) Q.push({T[v], dst[T[v]] = d+1});
    }
  }
  return ok;
}

bool dfs(int u, int d) {
  if (dst[u] != d) return 0;
  dst[u] = -1;

  for (auto v: adj[u]) {
    if (T[v] == -1 || dfs(T[v], d+1)) {
      S[u] = v, T[v] = u;
      return 1;
    }
  }
  return 0;
}

int match() {
  fill_n(S+1, N, -1);
  fill_n(T+1, N, -1);
  int cnt = 0;
  while (bfs()) {
    for (int u=1; u<=N; u++) cnt += dfs(u, 0);
  }
  return cnt;
}

void solve(int test) {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i].x >> P[i].y;
  cin >> J.x >> J.y;
  for (int i=1; i<=N; i++) cin >> Q[i].x >> Q[i].y;

  vector<int> idx;
  for (int i=1; i<=N; i++) idx.push_back(i);
  for (int i=1; i<=N; i++) {
    sort(all(idx), [&](int a, int b) { return dist(P[i], Q[a]) < dist(P[i], Q[b]); });
    adj[i].clear();
    for (auto j: idx) {
      if (dist(P[i], Q[j]) > dist(P[i], J)) break;
      adj[i].push_back(j);
    }
  }

  // match
  int cnt = match();
  if (cnt < N) {
    cout << "Case #" << test << ": IMPOSSIBLE" << endl;
    return;
  }

  // get ans
  vector<int> vstA(N+1), vstB(N+1);
  vector<pii> ans;

  while (1) {
    // match front
    for (int u=1; u<=N; u++) {
      if (vstA[u]) continue;
      int v = adj[u].front();
      if (S[u] == v) {
        vstA[u] = vstB[v] = 1;
        ans.push_back({u, v});
      }
    }

    if (sz(ans) == N) break;

    // update front
    for (int u=1; u<=N; u++) {
      if (vstA[u]) continue;
      while (vstB[adj[u].front()]) adj[u].pop_front();
    }

    // find cycle
    int u;
    for (u=1; u<=N; u++) if (!vstA[u]) break;

    vector<int> vst(N+1);
    while (!vst[u]) {
      vst[u] = 1;
      u = T[adj[u].front()];
    }
    int s = u;

    // augment cycle
    do {
      int v = adj[u].front(), nxt = T[v];
      S[u] = v, T[v] = u;
      u = nxt;
    } while (u != s);
  }

  cout << "Case #" << test << ": POSSIBLE" << endl;
  for (auto [u, v]: ans) cout << u << " " << v+1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
