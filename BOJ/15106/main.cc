#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

////////////////////////////////////////////////////////////////
lld T(lld a, lld b) {
  return (__int128)b*(b+1)/2 - (__int128)a*(a+1)/2;
}

lld S(lld a) {
  lld mid = max(sqrt(a)-5, 0.), sum = 0;
  for (lld i = 1; a/i > mid; i++) {
    sum += (a/i) * i;
  }
  for (lld k = mid; k >= 1; k--) {
    sum += T(a/(k+1), a/k) * k;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld a, b; cin >> a >> b;
  cout << S(b) - S(a-1) << endl;

  ////////////////////////////////
  return 0;
}
