#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, x[100'005], y[100'005];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
}

void calc() {
  double dist = INT_MAX;

  for (int i = 0; i < 1<<N; i++) {
    int e = 0;
    double xx = 0, yy = 0;

    for (int j = 0; j < N; j++) {
      if (i & (1<<j)) {
        e++; xx += x[j]; yy += y[j];
      } else {
        e--; xx -= x[j]; yy -= y[j];
      }
    }

    if (e == 0) dist = min(dist, sqrt(xx*xx + yy*yy));
  }

  cout << fixed << setprecision(9) << dist << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    calc();
  }

  ////////////////////////////////
  return 0;
}
