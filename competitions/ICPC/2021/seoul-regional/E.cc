#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld A, B, C;
lld rst;


lld f(lld x) {
  return (x % 2) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////
  cin >> A >> B >> C;

  for (lld i = 3; i <= A; i++) {
    if (i > C) break;
    if (i % 2)
      rst += min(i-1, min(B, C)) * 8;
    else {
      lld shld = min(B, C);
      if (shld >= i/2) shld--;
      rst += min(i-2, shld) * 8;
    }
  }


  for (lld i = 3; i <= B; i++) {
    if (i > A) break;
    if (i % 2)
      rst += min(i-1, min(A, C)) * 8;
    else {
      lld shld = min(A, C);
      if (shld >= i/2) shld--;
      rst += min(i-2, shld) * 8;
    }
  }

  for (lld i = 3; i <= C; i++) {
    if (i > B) break;
    if (i % 2)
      rst += min(i-1, min(B, A)) * 8;
    else {
      lld shld = min(B, A);
      if (shld >= i/2) shld--;
      rst += min(i-2, shld) * 8;
    }
  }

  cout << rst;


  ////////////////////////////////
  return 0;
}
