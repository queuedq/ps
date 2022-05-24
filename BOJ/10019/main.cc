#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const double eps = 1e-12;
int N;
double A[MN], B[MN], S[MN];

bool check(double K) {
  for (int i=1; i<=N; i++) {
    B[i] = A[i] - K;
    S[i] = S[i-1] + B[i];
  }
  
  double mx = -1e12, pmn = S[1];
  for (int i=2; i<=N-1; i++) {
    mx = max(mx, S[i] - pmn);
    pmn = min(pmn, S[i]);
  }

  return S[N] - mx <= 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  double l = 0, r = 10101;
  while (l+eps < r) {
    double m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }

  cout << fixed << setprecision(3) << r << endl;

  ////////////////////////////////
  return 0;
}
