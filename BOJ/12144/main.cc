#include <bits/stdc++.h>
#include <deque>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;

struct Flow {
  struct Edge { int v, cap, rid; };

  int N;
  vector<vector<Edge>> adj;
  vector<int> par;

  Flow(int N): N(N) {
    adj.resize(N);
    par.resize(N);
  }

  void add_edge(int u, int v, int w) {
    int id = sz(adj[u]), rid = sz(adj[v]);
    adj[u].push_back({v, w, rid});
    adj[v].push_back({u, 0, id});
  }

  int bfs(int s, int t) {
    fill(all(par), -1);
    par[s] = -2;
    deque<pii> Q = {{s, INF}};

    while (!Q.empty()) {
      auto [u, f] = Q.front(); Q.pop_front();

      for (auto &e: adj[u]) {
        if (par[e.v] != -1 || e.cap == 0) continue;
        par[e.v] = e.rid;
        int f1 = min(f, e.cap);
        if (e.v == t) return min(f, e.cap);
        Q.push_back({e.v, f1});
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int f, sum = 0;
    
    while ((f = bfs(s, t))) {
      int u = t;
      while (u != s) {
        Edge &e = adj[u][par[u]];
        adj[e.v][e.rid].cap -= f;
        e.cap += f;
        u = e.v;
      }
      sum += f;
    }
    return sum;
  }
};

int N;
vector<vector<int>> S;
unordered_map<string, int> id;

void solve(int test) {
  cin >> N;
  cin.ignore();

  for (int i=0; i<N; i++) {
    string line, word;
    getline(cin, line);

    // parse words
    istringstream ss(line);
    vector<int> words;
    while (getline(ss, word, ' ')) {
      if (id.count(word) == 0) id[word] = N + sz(id)*2;
      words.push_back(id[word]);
    }
    S.push_back(words);
  }

  // build graph
  Flow F(N + sz(id)*2);
  for (auto &[word, w]: id) F.add_edge(w, w+1, 1);
  for (int i=0; i<N; i++) {
    for (auto w: S[i]) {
      F.add_edge(i, w, INF);
      F.add_edge(w+1, i, INF);
    }
  }

  cout << "Case #" << test << ": " << F.max_flow(0, 1) << endl;
}

void reset() {
  S.clear();
  id.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
