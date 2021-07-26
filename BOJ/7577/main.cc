#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, N, D[41];

struct Edge { int u, v, w; };
vector<Edge> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> N;
  for (int i=0; i<K; i++) {
    E.push_back({i, i+1, 1});
    E.push_back({i+1, i, 0});
  }

  for (int i=0; i<N; i++) {
    int x, y, r; cin >> x >> y >> r;
    E.push_back({x-1, y, r});
    E.push_back({y, x-1, -r});
  }

  fill(D+1, D+K+1, INT_MAX);
  for (int i=0; i<=K+1; i++) {
    for (auto [u, v, w]: E) {
      if (D[v] > D[u] + w) {
        if (i == K+1) { cout << "NONE" << endl; return 0; }
        D[v] = D[u] + w;
      }
    }
  }
  
  for (int i=0; i<K; i++) {
    cout << (D[i+1] - D[i] ? '#' : '-');
  }

  ////////////////////////////////
  return 0;
}
