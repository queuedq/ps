#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N = 9;
vector<pii> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=N/3+1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) E.push_back({i, j});
  }

  for (int i=2; i<=N/3*2+2; i++) E.push_back({1, i});
  for (int i=2; i<=N/3; i++) E.push_back({N, i});

  cout << N << " " << E.size() << "\n";
  for (auto [i, j]: E) cout << i << " " << j << "\n";

  ////////////////////////////////
  return 0;
}
