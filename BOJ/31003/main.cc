#include <bits/stdc++.h>
#include <queue>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
int N, A[MN], deg[MN], ans[MN];
vector<int> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      if (gcd(A[i], A[j]) == 1) continue;
      adj[i].push_back(j);
      deg[j]++;
    }
  }
  
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int u=0; u<N; u++) {
    if (deg[u] == 0) pq.push({A[u], u});
  }

  for (int i=0; i<N; i++) {
    auto [a, u] = pq.top(); pq.pop();
    ans[i] = a;
    for (auto v: adj[u]) {
      if (--deg[v] == 0) pq.push({A[v], v});
    }
  }
  
  for (int i=0; i<N; i++) cout << ans[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
