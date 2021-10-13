#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
////////////////////////////////
lld w, h, L, ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> w >> h >> L;

  // bottom
  for (lld x=-L; x<=L; x++) {
    ans += floor(sqrt(L*L - x*x));
  }

  // left top
  for (lld x=-L; x<0; x++) {
    ans += floor(sqrt(L*L - x*x)) + 1;
  }

  // right top
  if (L <= w+h) {
    if (L > w) {
      for (lld x=1; x<=L-w; x++) {
        ans += floor(sqrt((L-w)*(L-w) - x*x)) + 1;
      }
    }
    if (L > h) {
      for (lld x=1; x<=L-h; x++) {
        ans += floor(sqrt((L-h)*(L-h) - x*x)) + 1;
      }
    }
  } else {
    for (lld x=0; x<=L; x++) {
      if (x <= w) {
        ans += floor(sqrt((L-h)*(L-h) - x*x)) + h;
      } else if (x <= L-h) {
        ans += max(
          floor(sqrt((L-h)*(L-h) - x*x)) + h,
          floor(sqrt((L-w)*(L-w) - (x-w)*(x-w)))
        );
      } else {
        ans += floor(sqrt((L-w)*(L-w) - (x-w)*(x-w)));
      }
    }
    ans += L+1;
    ans -= (w+1) * (h+1);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
