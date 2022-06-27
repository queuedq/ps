#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
vector<lld> A[MN];
vector<pll> E;

lld findMinClicks(int M, int R, vector<pii> P) {
  for (auto [y, x]: P) A[y].push_back(x*2);
  for (int y=0; y<M; y++) {
    sort(all(A[y]));
    A[y].push_back(A[y].back() - R*2);
    A[y].push_back(A[y][0] + R*2);
    sort(all(A[y]));
  }

  for (int y=0; y<M; y++) {
    for (auto x: A[y]) E.push_back({x, 2});
    for (int i=0; i<(int)A[y].size()-1; i++) {
      lld x1 = A[y][i], x2 = A[y][i+1];
      E.push_back({(x1+x2)/2, -2});
    }
  }
  sort(all(E));

  lld x = -R*2, s = -M, dst = 0, ans = LLONG_MAX;
  for (int y=0; y<M; y++) dst += A[y][0] - x;
  for (auto [x1, s1]: E) {
    dst += (x1-x) * s;
    x = x1;
    s += s1;
    ans = min(ans, dst);
  }
  
  return ans/2;
}
