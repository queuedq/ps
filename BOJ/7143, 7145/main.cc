#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> adj[300];

int main() {
  int tail = 2, tri = 15;
  
  for (int i=0; i<tail; i++) { // tail (multiplier)
    adj[tail].push_back({i, 0});
  }
  for (int i=0; i<tri; i++) { // triangles (2^n relaxation)
    int j = tail + i*2;
    adj[j+2].push_back({j, 0});
    adj[j+2].push_back({j+1, 0});
    adj[j+1].push_back({j, -(1<<i)});
  }

  int V = tail + tri*2 + 1, Q = 7, s = V-1, t = 0;

  cout << V << endl;
  for (int u=0; u<V; u++) {
    cout << adj[u].size() << " ";
    for (auto [v, w]: adj[u]) cout << v << " " << w << " ";
    cout << endl;
  }
  cout << Q << endl;
  for (int i=0; i<Q; i++) {
    cout << s << " " << t << endl;
  }
  return 0;
}
