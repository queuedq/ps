#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
llf maxProd(lld sum, lld n) {
  return pow((llf)sum / n, n);
}

lld calc(lld S, lld P) {
  if (S == P) { return 1; }
  lld l = 1, r = max((llf)2, (llf)S / exp(1));
  if (maxProd(S, r) < maxProd(S, r + 1)) r++;
  if (maxProd(S, r) < P) return -1;

  while (l + 1 < r) {
    lld mid = (l + r) / 2;
    if (maxProd(S, mid) >= P) r = mid;
    else l = mid;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld S, P; cin >> S >> P;
  cout << calc(S, P) << endl;

  ////////////////////////////////
  return 0;
}
