#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N;
set<lld> S;

void dfs(lld N) {
  if (S.find(N) != S.end()) return;
  S.insert(N);

  if (N%2 == 0) {
    dfs(N/2);
  } else {
    dfs(N/2); dfs(N/2+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;

    S.clear();
    S.insert(0);
    dfs(N);
    vector<lld> L(S.begin(), S.end());
    vector<pll> V;
    for (int i=1; i<L.size(); i++) {
      if (L[i] == 1) V.push_back({-1, -1});
      else if (L[i] % 2 == 0) {
        V.push_back({
          lower_bound(L.begin(), L.end(), L[i]/2) - L.begin() - 1,
          lower_bound(L.begin(), L.end(), L[i]/2) - L.begin() - 1
        });
      } else {
        V.push_back({
          lower_bound(L.begin(), L.end(), L[i]/2+1) - L.begin() - 1,
          lower_bound(L.begin(), L.end(), L[i]/2) - L.begin() - 1
        });
      }
    }

    cout << V.size() << endl;
    for (int i=0; i<V.size(); i++) {
      cout << V[i].first << " " << V[i].second << endl;
    }
    cout << V.size()-1 << endl;
  }

  ////////////////////////////////
  return 0;
}
