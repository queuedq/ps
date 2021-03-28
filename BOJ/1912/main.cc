#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, A[MAXN];

int solve(int l, int r) {
  if (l+1 == r) return A[l];

  int mid = (l+r)/2;
  int ret = max(solve(l, mid), solve(mid, r));

  int lsum = A[mid-1], rsum = A[mid], pre = 0;
  for (int i = mid-1; i >= l; i--) {
    pre += A[i];
    lsum = max(lsum, pre);
  }
  pre = 0;
  for (int i = mid; i < r; i++) {
    pre += A[i];
    rsum = max(rsum, pre);
  }

  return max(ret, lsum+rsum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  cout << solve(0, N) << endl;

  ////////////////////////////////
  return 0;
}
