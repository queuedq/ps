#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
int N;
vector<int> adj[MN];

int dfs(int u) {
  if (adj[u].size() == 0) return 0;
  
  vector<int> dp;
  for (auto v: adj[u]) {
    dp.push_back(dfs(v));
  }
  sort(dp.begin(), dp.end(), greater<int>());
  for (int i=0; i<dp.size(); i++) dp[i] += i+1;
  return *max_element(dp.begin(), dp.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int u=0; u<N; u++) {
    int p; cin >> p;
    if (p != -1) adj[p].push_back(u);
  }
  cout << dfs(0) << endl;

  ////////////////////////////////
  return 0;
}
