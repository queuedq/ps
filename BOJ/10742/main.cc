#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
int N, K;
double A[MN], psum[MN];

bool check(double X) {
  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i] - X;

  double mn = 0;
  for (int i=K; i<=N; i++) {
    mn = min(mn, psum[i-K]);
    if (psum[i] - mn >= 0) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];
  double l = 0, r = 1e6+5;
  while (l+1e-4 < r) {
    double m = (l+r) / 2;
    if (check(m)) l = m;
    else r = m;
  }
  cout << fixed << setprecision(6) << l << endl;

  ////////////////////////////////
  return 0;
}
