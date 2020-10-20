#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, sz[MAXN], cnt[MAXN];;
vector<int> adj[MAXN];

int dfs(int u, int p) {
  int s = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    s += dfs(v, u);
  }
  cnt[s]++;
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);

  for (int k=2; k<=N; k++) {
    if (N % k) continue;
    int g = N/k, tot = 0;
    for (int i=g; i<=N; i+=g) tot += cnt[i];
    if (tot == k) cout << k-1 << ' ';
  }

  ////////////////////////////////
  return 0;
}
