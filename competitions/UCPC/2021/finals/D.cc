#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
const int MX = 1e6+5;
struct Point { lld x, y, v; };
lld N, ans, xsum[MX], ysum[MX];
Point A[MN];
vector<lld> xs, ys;
vector<Point> xpoints[MX], ypoints[MX];

lld last_k(multiset<lld> &S, int k) {
  auto it = S.end(); it--;
  lld sum = 0;
  for (int i=0; i<k; i++, it--) {
    sum += *it;
    if (it == S.begin()) break;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y, v; cin >> x >> y >> v;
    A[i] = {x, y, v};
    xs.push_back(x);
    ys.push_back(y);
    xpoints[x].push_back(A[i]);
    ypoints[y].push_back(A[i]);
    xsum[x] += v;
    ysum[y] += v;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  // x axis
  multiset<lld> S;
  for (int i=0; i<xs.size(); i++) S.insert(xsum[xs[i]]);
  
  // x * 3
  ans = max(ans, last_k(S, 3));
  
  // x * 2, y * 1
  for (int i=0; i<ys.size(); i++) {
    for (auto [x, y, v]: ypoints[ys[i]]) {
      S.erase(S.find(xsum[x]));
      S.insert(xsum[x] - v);
    }

    ans = max(ans, last_k(S, 2) + ysum[ys[i]]);

    for (auto [x, y, v]: ypoints[ys[i]]) {
      S.erase(S.find(xsum[x] - v));
      S.insert(xsum[x]);
    }
  }

  // y axis
  S.clear();
  for (int i=0; i<ys.size(); i++) S.insert(ysum[ys[i]]);
  
  // y * 3
  ans = max(ans, last_k(S, 3));

  // x * 1, y * 2
  for (int i=0; i<xs.size(); i++) {
    for (auto [x, y, v]: xpoints[xs[i]]) {
      S.erase(S.find(ysum[y]));
      S.insert(ysum[y] - v);
    }

    ans = max(ans, last_k(S, 2) + xsum[xs[i]]);

    for (auto [x, y, v]: xpoints[xs[i]]) {
      S.erase(S.find(ysum[y] - v));
      S.insert(ysum[y]);
    }
  }

  // end
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
