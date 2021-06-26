#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, A[10101], mx;

bool check(int x) {
  lld sum = 0;
  for (int i=0; i<N; i++) sum += min(A[i], x);
  return sum <= M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  cin >> M;

  // always sum <= M at l, always sum > M at r
  int l = 0, r = M+1;
  while (l+1 < r) {
    int mid = (l+r)/2;
    if (check(mid)) l = mid;
    else r = mid;
  }

  cout << min(l, mx) << endl;

  ////////////////////////////////
  return 0;
}
