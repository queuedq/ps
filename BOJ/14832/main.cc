#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50'005;
int N, D[MN][6], S[MN*6], T[MN], vst[MN*6];
vector<int> adj[MN*6];

bool match(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;

  for (auto v: adj[u]) {
    if (!T[v] || match(T[v])) return S[u] = v, T[v] = u, true;
  }
  return 0;
}

void solve(int test) {
  // input
  cin >> N;
  vector<int> xs = {0};
  for (int i=1; i<=N; i++) {
    for (int j=0; j<6; j++) {
      cin >> D[i][j];
      xs.push_back(D[i][j]);
    }
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  for (int i=1; i<=N; i++) {
    for (int j=0; j<6; j++) {
      int x = lower_bound(xs.begin(), xs.end(), D[i][j]) - xs.begin();
      adj[x].push_back(i);
    }
  }

  // match
  int ans = 0;
  for (int i=1, j=1; j<=xs.size(); j++) {
    while (xs[j] != xs[j-1]+1 && i < j) T[S[i]] = 0, S[i] = 0, i++;
    while (i <= j) {
      fill(vst, vst+xs.size(), 0);
      if (match(j)) break;
      T[S[i]] = 0, S[i] = 0, i++;
    }
    ans = max(ans, j-i+1);
  }

  printf("Case #%d: %d\n", test, ans);

  // reset
  fill(S, S+xs.size(), 0);
  fill(T, T+N+1, 0);
  fill(adj, adj+xs.size(), vector<int>());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  for (int i=1; i<=t; i++) solve(i);

  ////////////////////////////////
  return 0;
}
