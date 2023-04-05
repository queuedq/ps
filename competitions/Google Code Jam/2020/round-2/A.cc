#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

ostream& operator<<(ostream& os, pll a) { os << "{" << a.first << "," << a.second << "}"; return os; }

////////////////////////////////////////////////////////////////
lld A, B;

lld sum1(lld i) {
  return i*(i+1)/2;
}

pll sum2(lld st, lld i) {
  lld l = (i+1)/2, r = i/2;
  lld lsum = (st+l-1) * l;
  lld rsum = (st+r) * r;
  return {lsum, rsum};
}

void calc(int test) {
  cin >> A >> B;
  lld cnt = 0;

  lld l = 0, r = 2e9;
  if (A > B) {
    while (l+1 < r) {
      lld mid = (l+r)/2;
      if (A - sum1(mid) < B) r = mid;
      else l = mid;
    }

    A -= sum1(l);
  } else if (A < B) {
    while (l+1 < r) {
      lld mid = (l+r)/2;
      if (B - sum1(mid) < A) r = mid;
      else l = mid;
    }

    B -= sum1(l);
  }
  cnt += l;

  l = 0; r = 2e9;
  if (A >= B) {
    while (l+1 < r) {
      lld mid = (l+r)/2;
      pll s = sum2(cnt+1, mid);
      if (s.first > A || s.second > B) r = mid;
      else l = mid;
    }

    pll s = sum2(cnt+1, l);
    A -= s.first; B -= s.second;
  } else {
    while (l+1 < r) {
      lld mid = (l+r)/2;
      pll s = sum2(cnt+1, mid);
      if (s.first > B || s.second > A) r = mid;
      else l = mid;
    }

    pll s = sum2(cnt+1, l);
    B -= s.first; A -= s.second;
  }
  cnt += l;

  cout << "Case #" << test << ": " << cnt << " " << A << " " << B << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i=1; i<=T; i++) {
    calc(i);
  }

  ////////////////////////////////
  return 0;
}
