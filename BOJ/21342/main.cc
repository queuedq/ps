#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using llf = long double;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, x[MN], v[MN], prv[MN], nxt[MN], vst[MN];

struct Node {
  llf t;
  int i, j;
  bool operator <(const Node &T) const { return t > T.t; }
};

llf inter(int i, int j) {
  if (v[i] == v[j]) return -INFINITY;
  return (llf)(x[j] - x[i]) / (v[i] - v[j]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> x[i] >> v[i];

  priority_queue<Node> pq;
  for (int i=1; i<=N-1; i++) {
    nxt[i] = i+1, prv[i+1] = i;
    llf t = inter(i, i+1);
    if (t >= 0) pq.push({t, i, i+1});
  }

  while (!pq.empty()) {
    auto [_, i, j] = pq.top(); pq.pop();
    if (vst[i] || vst[j]) continue;
    vst[i] = vst[j] = 1;
    int a = prv[i], b = nxt[j];
    nxt[a] = b, prv[b] = a;
    if (a == 0 || b == 0) continue;
    llf t = inter(a, b);
    if (t >= 0) pq.push({t, a, b});
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) if (!vst[i]) cnt++;
  cout << cnt << endl;
  for (int i=1; i<=N; i++) if (!vst[i]) cout << i << endl;

  ////////////////////////////////
  return 0;
}
