#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN =2e5+5;
int N, M;
int hand[MAXN][2], T[MAXN];
pii Q[MAXN*2];
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u, int t) {
  if (visited[u]) return;
  visited[u] = true;
  T[u] = t;
  for (auto v: adj[u]) dfs(v, t);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    int l, r; cin >> l >> r;
    if (l > 0) hand[i][0] = l;
    if (r > 0) hand[i][1] = r;
  }

  for (int i=1; i<=M; i++) {
    int x, h; cin >> x >> h; h--;
    Q[i] = {x, h};
    hand[x][h] = -hand[x][h];
  }

  for (int i=1; i<=N; i++) {
    for (int h=0; h<2; h++) {
      int j = hand[i][h];
      if (j > 0) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  fill(T, T+N+1, -1);
  dfs(1, -1);

  for (int i=M; i>=1; i--) {
    auto [x, h] = Q[i];
    hand[x][h] = -hand[x][h];
    int y = hand[x][h];
    if (!visited[x] || !visited[y]) {
      if (visited[x]) dfs(y, i-1);
      if (visited[y]) dfs(x, i-1);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }

  for (int i=1; i<=N; i++) {
    cout << T[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
