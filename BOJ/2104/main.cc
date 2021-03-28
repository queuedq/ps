#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, A[MAXN];

lld dnc(int l, int r) {
  if (l+1 == r) return A[l];

  int mid = (l+r)/2;
  lld ret = max(dnc(l, mid), dnc(mid, r));

  int i = mid-1, j = mid;
  lld h = INT_MAX, sum = 0;
  while (i >= l && j < r) {
    if (A[i] > A[j]) {
      h = min(h, A[i]);
      sum += A[i--];
    } else {
      h = min(h, A[j]);
      sum += A[j++];
    }
    ret = max(ret, (lld)h * sum);
  }
  while (i >= l) {
    h = min(h, A[i]);
    sum += A[i--];
    ret = max(ret, (lld)h * sum);
  }
  while (j < r) {
    h = min(h, A[j]);
    sum += A[j++];
    ret = max(ret, (lld)h * sum);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  cout << dnc(0, N) << endl;

  ////////////////////////////////
  return 0;
}
