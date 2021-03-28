#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M, K;
vector<pii> adj[MAXN];
int P[MAXN];
bool vst[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<K; i++) {
    cin >> P[i];
    vst[P[i]] = true;
  }
  for (int i=0; i<M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({w, b});
    adj[b].push_back({w, a});
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i=0; i<K; i++) {
    for (auto [w, u]: adj[P[i]]) {
      if (!vst[u]) pq.push({w, u});
    }
  }

  lld ans = 0;
  while (!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if (vst[u]) continue;
    vst[u] = true;
    ans += w;
    for (auto [x, v]: adj[u]) {
      if (!vst[v]) pq.push({x, v});
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
