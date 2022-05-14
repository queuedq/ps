#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MN = 15;
lld N;
pll A[10], B[11], D[1<<10][1<<10];
vector<pll> ans;

lld dst(int i, int j) {
  auto [x1, y1] = A[i];
  auto [x2, y2] = B[j];
  lld dx = x1-x2, dy = y1-y2;
  return dx*dx + dy*dy;
}

pll dp(int S, int T) {
  // which pair to choose from remaining set S(children), T(jelly)
  if (S == 0 && T == 0) return D[S][T] = {N, N};
  if (D[S][T] != pll(-2, -2)) return D[S][T];
  D[S][T] = pll(-1, -1); // (-1, -1): impossible

  for (int i=0; i<N; i++) {
    if (~S>>i&1) continue;
    
    // sort jelly by dist: (dist, idx)
    vector<pll> J;
    J.push_back({dst(i, N), N});
    for (int j=0; j<N; j++) {
      if (~T>>j&1) continue;
      J.push_back({dst(i, j), j});
    }
    sort(all(J));

    for (int k=0; k<J.size(); k++) {
      if (J[k].second == N || (k>0 && J[k-1].first < J[k].first)) break;
      // min dist jelly
      int j = J[k].second;

      auto [a, b] = dp(S^(1<<i), T^(1<<j));
      if (a != -1) { D[S][T] = {i, j}; break; }
    }
  }

  return D[S][T];
}

bool solve() {
  for (int i=0; i<1<<10; i++) fill(D[i], D[i]+(1<<10), pii(-2, -2));
  ans.clear();

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].first >> A[i].second;
  cin >> B[N].first >> B[N].second;
  for (int i=0; i<N; i++) cin >> B[i].first >> B[i].second;

  auto [a, b] = dp((1<<N)-1, (1<<N)-1);
  if (a == -1) return false;

  int S = (1<<N)-1, T = (1<<N)-1;
  while (S != 0) {
    auto [i, j] = D[S][T];
    ans.push_back({i, j});
    S ^= 1<<i; T ^= 1<<j;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    bool ok = solve();
    if (!ok) {
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << t << ": " << "POSSIBLE" << endl;
      for (auto [i, j]: ans) cout << i+1 << " " << j+2 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
