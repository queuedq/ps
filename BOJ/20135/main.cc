#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 205;
const int MM = 1005;
const int INF = INT_MAX;
int N, M;
int P[MN], cap[MN][MN], par[MN];

struct Edge { int u, v, l, r; } E[MM];

int flow(int s, int e) {
  fill(par, par+N+3, 0);
  deque<pii> Q = {{s, INF}};
  par[s] = -1;

  while (!Q.empty()) {
    auto [u, f] = Q.front(); Q.pop_front();
    for (int v=1; v<=N+2; v++) {
      if (!par[v] && cap[u][v]) {
        par[v] = u;
        if (v == e) return min(f, cap[u][v]);
        Q.push_back({v, min(f, cap[u][v])});
      }
    }
  }
  return 0;
}

int max_flow(int s, int e) {
  int f, sum = 0;
  while ((f = flow(s, e))) {
    for (int u=e; u!=s; u=par[u]) {
      cap[par[u]][u] -= f;
      cap[u][par[u]] += f;
    }
    sum += f;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int u=1; u<=N; u++) cin >> P[u];
  for (int i=1; i<=M; i++) {
    int u, v, l, r; cin >> u >> v >> l >> r;
    E[i] = {u, v, l, r};
    cap[u][v] = r-l, P[u] -= l, P[v] += l;
  }

  int pos = 0, neg = 0;
  for (int u=1; u<=N; u++) {
    if (P[u] > 0) pos += P[u], cap[N+1][u] = P[u];
    else neg += -P[u], cap[u][N+2] = -P[u];
  }

  int f = max_flow(N+1, N+2);
  if (pos != neg || pos != f) return cout << -1 << endl, 0;

  cout << 1 << endl;
  for (int i=1; i<=M; i++) {
    auto [u, v, l, r] = E[i];
    cout << r - cap[u][v] << endl;
  }

  ////////////////////////////////
  return 0;
}
