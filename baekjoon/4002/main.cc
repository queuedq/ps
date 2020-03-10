#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 1e5+5;
lld N, M, C[MAXN], L[MAXN];
vector<lld> child[MAXN];

lld dfs(lld u, priority_queue<lld> &p, lld &sum) {
  p.push(C[u]);
  sum += C[u];
  lld ans = 0;

  for (auto v: child[u]) {
    priority_queue<lld> q;
    lld s = 0;
    ans = max(ans, dfs(v, q, s));
    if (p.size() < q.size()) {
      swap(p, q);
      swap(sum, s);
    }
    while (q.size() > 0) {
      p.push(q.top());
      sum += q.top();
      q.pop();
    }
  }

  while (sum > M) {
    sum -= p.top();
    p.pop();
  }

  return max(ans, (lld)p.size() * L[u]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (lld i=1; i<=N; i++) {
    lld B; cin >> B >> C[i] >> L[i];
    child[B].push_back(i);
  }

  priority_queue<lld> p;
  lld sum = 0;
  lld ans = dfs(1, p, sum);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
