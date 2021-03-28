#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
int N, M, K, know[MAXN], adj[MAXN][MAXN];
vector<int> party[MAXN];

void dfs(int i) {
  know[i] = true;
  for (int j=1; j<=N; j++) {
    if (adj[i][j] && !know[j]) dfs(j);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;

  for (int i=0; i<K; i++) {
    int x; cin >> x;
    know[x] = true;
  }

  for (int i=0; i<M; i++) {
    int num; cin >> num;
    party[i].resize(num);
    for (int j=0; j<num; j++) {
      cin >> party[i][j];
      adj[party[i][0]][party[i][j]] = true;
      adj[party[i][j]][party[i][0]] = true;
    }
  }

  for (int i=1; i<=N; i++) {
    if (know[i]) dfs(i);
  }

  int ans = 0;
  for (int i=0; i<M; i++) {
    if (party[i].empty() || !know[party[i][0]]) ans++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
