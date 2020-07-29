#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
lld n, k, al, ar, bl, br;

void calc() {
  cin >> n >> k >> al >> ar >> bl >> br;
  lld l = min(al, bl), r = max(ar, br);

  lld zero = 0, one = 0;
  if (ar < bl) {
    zero = bl-ar;
    one = r-l;
  } else if (br < al) {
    zero = al-br;
    one = r-l;
  } else {
    zero = 0;
    one = (r-l)*2 - (ar-al + br-bl);
  }

  k -= max(0LL, ar-al + br-bl - (r-l)) * n;
  if (k <= 0) { cout << 0 << endl; return; }

  lld ans = 0, cnt = 0;
  while (k > 0) {
    if (cnt == n) { cout << ans + k*2 << endl; return; }
    if (k - one < 0) break;

    k -= one;
    ans += zero+one;
    cnt++;
  }

  if (cnt == 0) {
    cout << ans + zero+k << endl;
  } else {
    cout << min(ans + zero+k, ans + k*2) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  while (t--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
