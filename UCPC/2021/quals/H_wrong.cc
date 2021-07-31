#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int MK = 15;
lld N, M, K, S, T, dst[MN][MK];
vector<pll> adj[MN];
vector<int> rev[MN];

struct State {
  lld u, k, d;
  bool operator <(const State &s) const { return d > s.d; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K >> S >> T;
  for (int i=0; i<M; i++) {
    lld a, b, t; cin >> a >> b >> t;
    adj[a].push_back({b, t});
    rev[b].push_back(a);
  }
  for (int i=0; i<M; i++) fill(dst, dst+K+1, LLONG_MAX);

  priority_queue<State> pq;
  pq.push({S, 0, 0});
  while (!pq.empty()) {
    auto [u, k, d] = pq.top(); pq.pop();
    if (dst[u][k] != LLONG_MAX) continue;
    dst[u][k] = d;

    for (auto [v, t]: adj[u]) {
      pq.push({v, k, d+t});
    }
    if (k < K) {
      for (auto v: rev[u]) {
        pq.push({v, k+1, d});
      }
    }
  }

  ////////////////////////////////
  return 0;
}
