#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1505;
int N;
pii P[MAXN];

int gcd(int a, int b) {
  while (b != 0) { int r = a % b; a = b; b = r; }
  return abs(a);
};

pii slope(pii a) {
  auto [x, y] = a;
  int g = gcd(x, y);
  x = x/g; y = y/g;
  if (x > 0) return {x, y};
  if (x < 0) return {-x, -y};
  return {0, 1};
}

pii ortho(pii a) {
  auto [x, y] = a;
  if (y > 0) return {y, -x};
  if (y < 0) return {-y, x};
  return {0, 1};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    P[i] = {x, y};
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    map<pii, int> slopes;
    for (int j=0; j<N; j++) {
      if (i == j) continue;
      pii s = slope({P[i].first - P[j].first, P[i].second - P[j].second});
      slopes[s]++;
    }

    for (auto [s, cnt]: slopes) {
      auto it = slopes.find(ortho(s));
      if (it == slopes.end()) continue;
      ans += cnt * it->second;
    }
  }

  cout << ans / 2 << endl;

  ////////////////////////////////
  return 0;
}
