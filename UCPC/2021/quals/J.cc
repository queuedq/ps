#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

pii operator +(pii a, pii b) {
  return {a.first + b.first, a.second + b.second};
}
pii operator -(pii a, pii b) {
  return {a.first - b.first, a.second - b.second};
}

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, ans;
pii A[MN]; // {2U-C, 2P-C}
vector<int> adj[MN];

void dfs(int u, int p, map<pii, int> &cnt) {
  A[u] = A[u] + A[p];
  for (auto v: adj[u]) {
    if (v == p) continue;

    map<pii, int> sub;
    dfs(v, u, sub);
    ans += sub[A[p]];

    if (cnt.size() < sub.size()) swap(cnt, sub);
    for (auto [a, k]: sub) ans += (lld)cnt[A[u] + A[p] - a] * k;
    for (auto [a, k]: sub) cnt[a] += k;
  }
  cnt[A[u]]++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    char c; cin >> c;
    if (c == 'U') A[i] = {2, 0};
    else if (c == 'P') A[i] = {0, 2};
    else A[i] = {-1, -1};
  }
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  map<pii, int> cnt;
  dfs(1, 0, cnt);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
