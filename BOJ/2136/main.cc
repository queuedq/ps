#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, L;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  int last = 0, mx = 0, left = 0;

  for (int i=1; i<=N; i++) {
    int x; cin >> x;
    if (x > 0) {
      A[i] = {x, i};
      if (L-x > mx) last = 1, mx = L-x;
    } else {
      A[i] = {-x, i};
      if (-x > mx) last = -1, mx = -x;
      left++;
    }
  }

  if (last == -1) left--;

  sort(A+1, A+N+1);
  cout << A[left + 1].second << " " << mx << endl;

  ////////////////////////////////
  return 0;
}
