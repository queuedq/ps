#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const double PI = acos(0)*2;
lld N;

struct Point {
  lld x, y;
  double p, angle;
  bool operator <(Point P) const { return angle < P.angle; }
} A[MAXN];

double l[2][MAXN], r[2][MAXN];

void solve(int test) {
  cin >> N;

  for (int i=0; i<N; i++) cin >> A[i].x;
  for (int i=0; i<N; i++) cin >> A[i].y;
  for (int i=0; i<N; i++) cin >> A[i].p;

  int a, b; cin >> a >> b;
  for (int i=0; i<N; i++) {
    A[i].x -= a;
    A[i].y -= b;
    A[i].angle = atan2(A[i].y, A[i].x);
  }

  sort(A, A+N);
  int mid = lower_bound(A, A+N, Point({0, 0, 0, 0})) - A;

  l[0][0] = r[0][0] = 1;
  for (int i=0; i<mid; i++) {
    l[0][i+1] = l[0][i] * (1-A[i].p);
    r[0][i+1] = r[0][i] * (1-A[mid-i-1].p);
  }

  l[1][0] = r[1][0] = 1;
  for (int i=0; i<N-mid; i++) {
    l[1][i+1] = l[1][i] * (1-A[i+mid].p);
    r[1][i+1] = r[1][i] * (1-A[N-i-1].p);
  }

  double ans = 0;

  int j = 0;
  for (int i=mid; i<N; i++) {
    while (A[i].angle - A[j].angle > PI) j++;
    ans += l[0][j] * r[1][N-i-1] * A[i].p;
  }

  for (int i=0; i<mid; i++) {
    while (j < N && A[j].angle - A[i].angle < PI) j++;
    ans += l[1][j-mid] * r[0][mid-i-1] * A[i].p;
  }

  ans += l[0][mid] * l[1][N-mid];
  ans = 1 - ans;

  cout << "Case #" << test << endl;
  cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
