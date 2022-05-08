#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
const llf eps = 1e-12;
int N, L, bs, be;
llf A[MN], psum[MN];

bool check(llf X) {
  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i] - X;

  llf mn = 0;
  for (int i=L; i<=N; i++) {
    if (psum[i-L] <= mn) mn = psum[i-L];
    if (psum[i] - mn >= 0) return true;
  }
  return false;
}

void ans(llf X) {
  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i] - X;

  llf mn = 0;
  int s = 0, e = 0, bl = MN;
  for (int i=L; i<=N; i++) {
    if (psum[i-L] <= mn + eps) {
      mn = psum[i-L];
      s = i-L+1;
    }
    if (psum[i] - mn >= -eps) {
      e = i;
      if (e-s+1 < bl) bs = s, be = e, bl = e-s+1;
    }
  }
}

void solve() {
  cin >> N >> L;
  for (int i=1; i<=N; i++) { char c; cin >> c; A[i] = c - '0'; }
  llf l = 0, r = 1 + eps;
  while (l + eps < r) {
    llf m = (l+r) / 2;
    if (check(m)) l = m;
    else r = m;
  }
  ans(l);
  cout << bs << " " << be << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
