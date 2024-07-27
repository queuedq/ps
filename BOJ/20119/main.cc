#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M, L;
vector<int> recipe[MN], idx[MN];
int result[MN];
int cnt[MN], vst[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      recipe[i].push_back(x);
      idx[x].push_back(i);
    }
    cin >> result[i];
  }

  queue<int> Q;
  cin >> L;
  for (int i=0; i<L; i++) {
    int y; cin >> y;
    Q.push(y);
  }

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    if (vst[u]) continue;
    vst[u] = 1;
    for (auto i: idx[u]) {
      if (++cnt[i] == sz(recipe[i])) Q.push(result[i]);
    }
  }
  
  vector<int> ans;
  for (int u=1; u<=N; u++) {
    if (vst[u]) ans.push_back(u);
  }

  cout << sz(ans) << endl;
  for (int u: ans) cout << u << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
