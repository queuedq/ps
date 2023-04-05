#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
};
lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }
////////////////////////////////
const int MN = 505;
int N, cnt[MN][MN];
Point A[MN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].x >> A[i].y;
  sort(A, A+N);

  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=i+1; k<j; k++) {
        if (ccw(A[i], A[k], A[j]) > 0) cnt[i][j]++;
      }
    }
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=j+1; k<N; k++) {
        if (ccw(A[i], A[j], A[k]) > 0) {
          if (cnt[i][k] - cnt[i][j] - cnt[j][k] - 1 != 0) ans++;
        } else {
          if (cnt[i][j] + cnt[j][k] - cnt[i][k] != 0) ans++;
        }
      }
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
