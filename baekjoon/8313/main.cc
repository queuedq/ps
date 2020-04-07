#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point {
  lld x, y;
  bool operator <(Point a) const { return x == a.x ? y < a.y : x < a.x; }
};

const int MAXN = 30;
lld N, A[MAXN];
vector<Point> L, R;
map<lld, lld> S;

void half(lld a, lld b, lld c, lld s, lld e, vector<Point> &V) {
  if (s == e) return V.push_back({b - a, c - b});
  half(a+A[s], b, c, s+1, e, V);
  half(a, b+A[s], c, s+1, e, V);
  half(a, b, c+A[s], s+1, e, V);
}

void insert(lld y, lld val) {
  auto it = S.lower_bound(y);
  if (it != S.end() && val >= it->second) return; // Dominated
  while (true) {
    auto it = S.upper_bound(y);
    if (it == S.begin()) break;
    it--;
    if (val <= it->second) S.erase(it); // Dominating
    else break;
  }
  S[y] = val;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  half(0, 0, 0, 0, N/2, L);
  half(0, 0, 0, N/2, N, R);

  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  lld ans = LLONG_MAX;
  int j = L.size() - 1;
  for (int i=0; i<R.size(); i++) {
    while (j >= 0 && L[j].x + R[i].x >= 0) {
      insert(L[j].y, L[j].x + L[j].y);
      j--;
    }
    auto it = S.lower_bound(-R[i].y);
    if (it == S.end()) continue;
    ans = min(ans, it->second + R[i].x + R[i].y);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
