#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
using lld = long long;

////////////////////////////////////////////////////////////////
int N;
struct Square {
  int x, y, r, i;
  bool operator<(const Square &S) const { return r < S.r; }

  bool overlaps(Square &S) {
    bool x_overlap = max(x-r, S.x-S.r) < min(x+r, S.x+S.r);
    bool y_overlap = max(y-r, S.y-S.r) < min(y+r, S.y+S.r);
    return x_overlap && y_overlap;
  }
};
vector<Square> S, res;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int x, y, r; cin >> x >> y >> r;
    S.push_back({x, y, r, i});
  }
  sort(all(S));
  reverse(all(S));

  for (int i=0; i<N; i++) {
    bool ok = true;
    for (auto &sq: res) {
      if (S[i].overlaps(sq)) { ok = false; break; }
    }
    if (ok) res.push_back(S[i]);
  }

  cout << sz(res) << endl;
  for (auto &sq: res) {
    cout << sq.i << endl;
  }

  ////////////////////////////////
  return 0;
}
