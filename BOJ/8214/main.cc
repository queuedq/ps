#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, m;
int adj[3001][3001];
int ans[3001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int a, b; cin >> a >> b;
    adj[a][b] = adj[b][a] = 1;
  }

  fill(ans+1, ans+n+1, 1);

  for (int i=1; i<=n; i++) {
    for (int j=1; j<i; j++) {
      if (adj[i][j]) continue;
      if (ans[i] & ans[j]) ans[i] = ans[j] = 0;
    }
  }

  for (int i=1, cnt=0; i<=n && cnt<n/3; i++) {
    if (ans[i]) {
      cout << i << " ";
      cnt++;
    }
  }

  ////////////////////////////////
  return 0;
}
