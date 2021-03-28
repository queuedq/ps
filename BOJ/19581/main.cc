#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
vector<pii> adj[MAXN];
vector<int> D;

vector<pii> dfs(int u, int p) {
  vector<pii> H;

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    auto h = dfs(v, u);
    for (int i=0; i<h.size(); i++) H.push_back({h[i].first+w, v});
    H.push_back({w, v});
  }

  sort(H.rbegin(), H.rend());

  for (int i=0; i<H.size() && i<7; i++) {
    D.push_back(H[i].first);
    for (int j=i+1; j<H.size() && j<7; j++) {
      if (H[i].second == H[j].second) continue;
      D.push_back(H[i].first + H[j].first);
    }
  }

  H.resize(min((int)H.size(), 2));
  return H;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  dfs(1, 0);
  sort(D.rbegin(), D.rend());
  cout << D[1] << endl;

  ////////////////////////////////
  return 0;
}
