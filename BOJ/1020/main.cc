#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int seg[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int L, K, N[20], ans[20];
// L: length of N
// K: target # segs

lld get_num(int arr[20]) {
  lld ret = 0;
  for (int i=0; i<L; i++) ret = ret*10 + arr[i];
  return ret;
}

lld get_diff() {
  lld ret = get_num(ans) - get_num(N);
  if (ret <= 0) {
    lld p = 1;
    for (int i=0; i<L; i++) p *= 10;
    ret += p;
  }
  return ret;
}

bool solve(int i, bool b, int cnt) {
  // determine i-th digit
  // b: first i-1 digits match N
  // cnt: current # segs
  if (i == L) return !b && cnt == K;
  if (K-cnt < (L-i) * 2 || K-cnt > (L-i) * 7) return false;

  if (b) {
    for (int d=N[i]; d<=9; d++) {
      ans[i] = d;
      bool ok = solve(i+1, d==N[i], cnt+seg[d]);
      if (ok) return true;
    }
  } else {
    for (int d=0; d<=9; d++) {
      ans[i] = d;
      bool ok = solve(i+1, 0, cnt+seg[d]);
      if (ok) return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string S; cin >> S; L = S.size();
  for (int i=0; i<L; i++) {
    N[i] = S[i] - '0';
    K += seg[N[i]];
  }

  if (solve(0, 1, 0)) {
    cout << get_diff() << endl;
  } else {
    solve(0, 0, 0);
    cout << get_diff() << endl;
  }

  ////////////////////////////////
  return 0;
}
