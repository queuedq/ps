#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 202020;
int N, Q;
vector<pll> H[MX], V[MX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    int x, y, w; cin >> x >> y >> w;
    H[x].push_back({y, w});
    V[y].push_back({x, w});
  }

  // prefix sum
  for (int x=0; x<MX; x++) {
    H[x].push_back({0, 0});
    sort(H[x].begin(), H[x].end());
    for (int i=1; i<(int)H[x].size(); i++) H[x][i].second += H[x][i-1].second;
  }

  for (int y=0; y<MX; y++) {
    V[y].push_back({0, 0});
    sort(V[y].begin(), V[y].end());
    for (int i=1; i<(int)V[y].size(); i++) V[y][i].second += V[y][i-1].second;
  }

  // query
  int x = 1, y = 1;
  lld sum = 0;
  for (int q=0; q<Q; q++) {
    int d, v; cin >> d >> v;

    if (d == 0) { // ver +
      int s = x, e = x + v;
      int si = lower_bound(V[y].begin(), V[y].end(), pll(s+1, 0)) - V[y].begin();
      int ei = lower_bound(V[y].begin(), V[y].end(), pll(e+1, 0)) - V[y].begin();
      sum += V[y][ei-1].second - V[y][si-1].second;
      x += v;
    } else if (d == 1) { // hor +
      int s = y, e = y + v;
      int si = lower_bound(H[x].begin(), H[x].end(), pll(s+1, 0)) - H[x].begin();
      int ei = lower_bound(H[x].begin(), H[x].end(), pll(e+1, 0)) - H[x].begin();
      sum += H[x][ei-1].second - H[x][si-1].second;
      y += v;
    } else if (d == 2) { // ver -
      int s = x, e = x - v;
      int si = lower_bound(V[y].begin(), V[y].end(), pll(s, 0)) - V[y].begin();
      int ei = lower_bound(V[y].begin(), V[y].end(), pll(e, 0)) - V[y].begin();
      sum += V[y][si-1].second - V[y][ei-1].second;
      x -= v;
    } else if (d == 3) { // hor -
      int s = y, e = y - v;
      int si = lower_bound(H[x].begin(), H[x].end(), pll(s, 0)) - H[x].begin();
      int ei = lower_bound(H[x].begin(), H[x].end(), pll(e, 0)) - H[x].begin();
      sum += H[x][si-1].second - H[x][ei-1].second;
      y -= v;
    }
  }

  cout << sum << endl;

  ////////////////////////////////
  return 0;
}
