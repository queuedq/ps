#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

////////////////////////////////////////////////////////////////

lld S(lld a, lld b) {
  lld mid = sqrt(b), sum = 0;
  for (lld i = 1; i <= mid; i++) {
    sum += (b/i - (a-1)/i) * i;
    lld l = max((a-1)/i, mid), r = b/i;
    if (l < r) {
      sum += (l+r+1) * (r-l) / 2;
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld a, b; cin >> a >> b;
  cout << S(a, b) << endl;

  ////////////////////////////////
  return 0;
}
