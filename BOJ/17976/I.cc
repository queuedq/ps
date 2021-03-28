#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
pii A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, l; cin >> x >> l;
    A[i] = {x, x+l};
  }

  sort(A, A+N);

  lld l = 0, r = INT_MAX;
  while (l+1 < r) {
    lld m = (l+r)/2;
    lld x = INT_MIN;
    bool ok = true;
    for (lld i=0; i<N; i++) {
      if (x + m <= A[i].first) x = A[i].first;
      else if (x + m <= A[i].second) x += m;
      else { ok = false; break; }
    }
    if (ok) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
