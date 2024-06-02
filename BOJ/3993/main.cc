#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct RegexParser {
  enum Type { PAREN, GRAPH };

  struct Partial {
    int type;
    int s, m, e; // start, before end, end
    void add_end(int f) { m = e; e = f; }
  };

  int N = 0;
  vector<vector<pair<int, char>>> adj = {{}};

  int add_vertex() {
    adj.push_back({});
    return ++N;
  }

  void add_edge(int u, int v, char c) {
    adj[u].push_back({v, c});
  }

  void parse(string R) {
    R = "(" + R + ")"; // handle "|"s without parens
    vector<Partial> S;
    int s = add_vertex();
    S.push_back({GRAPH, s, 0, s});

    for (int i=0; i<sz(R); i++) {
      switch (R[i]) {
        case '(': {
          int s = add_vertex();
          int s1 = add_vertex();
          add_edge(S.back().e, s, 0);
          S.back().add_end(s);
          S.push_back({PAREN, 0, 0, 0});
          S.push_back({GRAPH, s1, 0, s1});
          break;
        }

        case '|': {
          int s = add_vertex();
          S.push_back({GRAPH, s, 0, s});
          break;
        }

        case ')': {
          int p = sz(S)-1;
          while (S[p].type != PAREN) p--; // find paren

          int e = add_vertex();
          for (int j=p+1; j<sz(S); j++) { // merge "|"
            add_edge(S[p-1].e, S[j].s, 0);
            add_edge(S[j].e, e, 0);
          }

          S.resize(p);
          S[p-1].add_end(e);
          break;
        }

        case '*': {
          auto [t, s, m, e] = S.back();
          add_edge(m, e, 0);
          add_edge(e, m, 0);
          break;
        }

        default: { // alphabet
          int s = add_vertex();
          int e = add_vertex();
          add_edge(S.back().e, s, 0);
          add_edge(s, e, R[i]);
          S.back().m = s;
          S.back().e = e;
          break;
        }
      }
    }
  }

  void debug() {
    cout << N << endl;
    for (int i=1; i<=N; i++) {
      for (auto [v, c]: adj[i]) {
        cout << i << " -(" << (c == 0 ? ' ' : c) << ")> " << v << endl;
      }
    }
  }
};

////////////////////////////////////////////////////////////////
const int INF = 1e9;
struct Pos { int a, b, d; };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string A, B;
  cin >> A >> B;
  
  // parse NFA
  RegexParser G, H;
  G.parse(A);
  H.parse(B);

  // G.debug();
  // H.debug();

  // shortest path on cartesian product
  vector<vector<vector<int>>> dst(G.N+1); // index: a, b, (non-zero?)
  vector<vector<vector<array<int, 3>>>> par(G.N+1);
  for (int i=1; i<=G.N; i++) {
    dst[i].assign(H.N+1, {INF, INF});
    par[i].assign(H.N+1, {{}, {}});
  }

  deque<Pos> Q;
  Q.push_back({1, 1, 0});
  dst[1][1][0] = 0;

  while (!Q.empty()) {
    auto [a, b, d] = Q.front(); Q.pop_front();
    if (d > dst[a][b][d > 0]) continue;

    // eps
    for (auto [x, c]: G.adj[a]) {
      if (c) continue;
      if (d < dst[x][b][d > 0]) {
        Q.push_front({x, b, d});
        dst[x][b][d > 0] = d;
        par[x][b][d > 0] = {a, b};
      }
    }
    for (auto [y, c]: H.adj[b]) {
      if (c) continue;
      if (d < dst[a][y][d > 0]) {
        Q.push_front({a, y, d});
        dst[a][y][d > 0] = d;
        par[a][y][d > 0] = {a, b, 0};
      }
    }

    // alphabet
    for (auto [x, c]: G.adj[a]) {
      if (!c) continue;
      for (auto [y, c1]: H.adj[b]) {
        if (c != c1) continue;
        if (d+1 < dst[x][y][1]) {
          Q.push_back({x, y, d+1});
          dst[x][y][1] = d+1;
          par[x][y][1] = {a, b, c};
        }
      }
    }
  }

  // traceback
  if (dst[G.N][H.N][1] == INF) {
    cout << "Correct" << endl;
  } else {
    cout << "Wrong" << endl;
    int x = G.N, y = H.N, d = dst[x][y][1];
    string S;
    while (x != 1 || y != 1 || d != 0) {
      auto [a, b, c] = par[x][y][d > 0];
      if (c) S.push_back(c), d--;
      x = a, y = b;
    }
    reverse(all(S));
    cout << S << endl;
  }

  ////////////////////////////////
  return 0;
}
