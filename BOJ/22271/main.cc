#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e7;
const int MN = 105;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  n++;
  capacity.resize(n);
  capacity[0].resize(n);
  adj.resize(n);

  int K1;
  for (int i=1; i<n; i++) {
    capacity[i].resize(n);

    string S; cin >> S;
    if (S == "*") {
      if (i == 1) K1 = INF;
      int L; cin >> L;
      if (L == 1) L = 0; // s=1, t=0
      capacity[i][L] = INF;
      adj[i].push_back(L);
    } else {
      int K = stoi(S);
      if (i == 1) K1 = K;
      for (int j=0; j<K; j++) {
        int L; cin >> L;
        if (L == 1) L = 0; // s=1, t=0
        capacity[i][L]++;
      }
      for (int L=0; L<n; L++) {
        if (capacity[i][L]) adj[i].push_back(L);
      }
    }
  }
  
  int flow = maxflow(1, 0);
  if (flow == INF) cout << "*" << endl;
  else cout << flow + 1 << endl;

  ////////////////////////////////
  return 0;
}
