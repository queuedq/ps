#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2005;
lld N, H[MN], D[MN];

struct Line {
  int s, e;
  bool operator <(const Line &L) const {
    if ((H[e] - H[s]) * (L.e - L.s) == (H[L.e] - H[L.s]) * (e - s)) {
      return e < L.e;
    }
    return (H[e] - H[s]) * (L.e - L.s) < (H[L.e] - H[L.s]) * (e - s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> H[i];
  fill(D, D+N, 1);

  vector<Line> L;
  for (int j=0; j<N; j++) {
    for (int i=0; i<j; i++) L.push_back({i, j});
  }
  sort(L.begin(), L.end());

  for (auto [s, e]: L) D[e] = max(D[e], D[s] + 1);
  cout << N - *max_element(D, D+N) << endl;

  ////////////////////////////////
  return 0;
}
