#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
#define X first
#define Y second

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, M;
pll A[MN], B[MN];
vector<pll> slopes;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i].X >> A[i].Y;
    A[i].X--;
  }
  cin >> M;
  for (int i=0; i<M; i++) {
    cin >> B[i].X >> B[i].Y;
    B[i].X--;
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      vector<lld> e;
      e.push_back(A[i].X + B[j].X);
      e.push_back(A[i].X + B[j].Y);
      e.push_back(A[i].Y + B[j].X);
      e.push_back(A[i].Y + B[j].Y);
      sort(e.begin(), e.end());
      slopes.push_back({e[0], 1});
      slopes.push_back({e[1], -1});
      slopes.push_back({e[2], -1});
      slopes.push_back({e[3], 1});
    }
  }

  sort(slopes.begin(), slopes.end());

  lld ans = 0, mx = 0, x0 = 0, y = 0, s = 0;
  for (auto [x, d]: slopes) {
    y += (x-x0) * s;
    if (y > mx) {
      ans = x;
      mx = y;
    }
    x0 = x;
    s += d;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
