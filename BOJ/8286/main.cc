#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e6+5;
int N, deg[MN];
vector<pii> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<int> A, B;
  for (int u=1; u<=N; u++) {
    cin >> deg[u];
    if (deg[u] == 1) A.push_back(u);
    else B.push_back(u);
  }

  while (!A.empty() && !B.empty()) {
    int u = A.back(), v = B.back();
    ans.push_back({u, v});
    deg[u]--, deg[v]--;
    A.pop_back();
    if (deg[v] == 1) { B.pop_back(); A.push_back(v); }
  }
  
  if (sz(A) == 2 && sz(B) == 0) {
    ans.push_back({A[0], A[1]});
    for (auto [u, v]: ans) cout << u << " " << v << endl;
  } else {
    cout << "BRAK" << endl;
  }

  ////////////////////////////////
  return 0;
}
