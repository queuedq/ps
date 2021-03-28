#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int X, Y, D, T;

double dist(int x, int y) {
  return sqrt(x*x + y*y);
}

double calc() {
  if (T >= D) { return dist(X, Y); }

  if (dist(X, Y) < D) {
    double t0 = dist(X, Y);
    double t1 = T + (D - dist(X, Y));
    double t2 = T * 2;

    return min(t0, min(t1, t2));
  }

  double jumps = floor(dist(X, Y) / D);
  double t0 = jumps * T + (dist(X, Y) - jumps * D);
  double t1 = (jumps + 1) * T;

  return min(t0, t1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> X >> Y >> D >> T;
  cout << fixed << setprecision(12) << calc() << endl;

  ////////////////////////////////
  return 0;
}
