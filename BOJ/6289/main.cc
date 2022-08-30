#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MD = 19;
int N[MD];
lld pow8[MD];

lld solve(int d, int less, int zero, int a, int b) {
  // ab??? / determine d-th digit
  // less: prefix = N's MSDs (<= than N's LSDs)
  // zero: prefix = zeros
  if (d < 0) return 1;
  if (!less && a != -1 && b != -1) return pow8[d+1];
  
  lld res = 0;
  for (int i=0; i<=9; i++) {
    if (i == a || i == b) continue;
    int z = zero && (i==0);
    int c = z ? -1 : i;
    if (less) {
      if (i < N[d]) res += solve(d-1, 0, z, b, c);
      else if (i == N[d]) res += solve(d-1, 1, z, b, c);
      else break;
    } else {
      res += solve(d-1, 0, z, b, c);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  pow8[0] = 1;
  for (int i=1; i<MD; i++) pow8[i] = pow8[i-1] * 8;

  lld a, b; cin >> a >> b; a--;

  lld ans = 0;
  for (int i=0; i<MD; i++) { N[i] = b%10; b/=10; }
  ans += solve(MD-1, 1, 1, -1, -1);
  for (int i=0; i<MD; i++) { N[i] = a%10; a/=10; }
  ans -= solve(MD-1, 1, 1, -1, -1);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
