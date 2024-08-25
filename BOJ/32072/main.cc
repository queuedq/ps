#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, A[MN];
vector<int> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int u=2; u<=N; u++) {
    int p; cin >> p;
    adj[p].push_back(u);
  }
  for (int u=1; u<=N; u++) cin >> A[u];

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({A[1], 1});
  for (int i=1; i<=N; i++) {
    auto [a, u] = pq.top(); pq.pop();
    cout << a << endl;
    for (auto v: adj[u]) pq.push({A[v], v});
  }

  ////////////////////////////////
  return 0;
}
