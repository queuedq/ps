#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'005;
int N;
vector<int> adj[MN];
priority_queue<lld> pq[MN];

struct Bridge {
  lld s, e, v;
  bool operator <(Bridge B) const { return pll(s, -e) < pll(B.s, -B.e); }
};
Bridge B[MN];

void dfs(int u) {
  for (auto v: adj[u]) {
    dfs(v);
    if (sz(pq[u]) < sz(pq[v])) swap(pq[u], pq[v]);
    
    vector<lld> sum;
    while (sz(pq[v])) {
      sum.push_back(pq[u].top() + pq[v].top());
      pq[u].pop(); pq[v].pop();
    }
    for (auto s: sum) pq[u].push(s);
  }

  pq[u].push(B[u].v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { cin >> B[i].s >> B[i].e >> B[i].v; }
  sort(B+1, B+N+1);
  B[0] = {0, INT_MAX, 0};

  // build tree
  vector<int> stk = {0};
  for (int i=1; i<=N; i++) {
    while (B[stk.back()].e < B[i].e) stk.pop_back();
    int p = stk.back();
    adj[p].push_back(i);
    stk.push_back(i);
  }

  // greedy
  dfs(0);

  lld ans = 0;
  for (int i=1; i<=N; i++) {
    if (sz(pq[0])) { ans += pq[0].top(); pq[0].pop(); }
    cout << ans << ' ';
  }

  ////////////////////////////////
  return 0;
}
