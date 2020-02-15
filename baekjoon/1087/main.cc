#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 55;
const double eps = 1e-12;
int N, px[MAX_N], py[MAX_N], vx[MAX_N], vy[MAX_N];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> px[i] >> py[i] >> vx[i] >> vy[i];
  }
}

double boundingBox(double t) {
  double minX = 1e9, maxX = -1e9;
  double minY = 1e9, maxY = -1e9;

  for (int i = 0; i < N; i++) {
    minX = min(minX, px[i] + vx[i] * t);
    maxX = max(maxX, px[i] + vx[i] * t);
    minY = min(minY, py[i] + vy[i] * t);
    maxY = max(maxY, py[i] + vy[i] * t);
  }
  return max(maxX - minX, maxY - minY);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  double l = 0, r = 100000;

  while (true) {
    double ml = (l*2+r)/3, mr = (l+r*2)/3;
    double bl = boundingBox(ml), br = boundingBox(mr);
    if (abs(bl-br) < eps) { l = ml; r = mr; break; }
    if (bl > br) l = ml;
    else r = mr;
  }

  cout << setprecision(12) << boundingBox((l+r) / 2) << endl;

  ////////////////////////////////
  return 0;
}
