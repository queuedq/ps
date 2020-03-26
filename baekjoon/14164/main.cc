#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point { lld x, y; };

ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
lld cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b - a, c - a); }

const int MAXN = 305;
int N, cnt[MAXN][MAXN], ans[MAXN];
Point P[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  sort(P, P+N);

  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=j+1; k<N; k++) {
        if (ccw(P[i], P[j], P[k]) > 0) cnt[i][k]++;
      }
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=j+1; k<N; k++) {
        int inner = cnt[i][k] - cnt[i][j] - cnt[j][k];
        if (inner > 0) inner--;
        ans[abs(inner)]++;
      }
    }
  }

  for (int i=0; i<N-2; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
