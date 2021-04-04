#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int n;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=0; i<n; i++) {
    int x, w; cin >> x >> w;
    A[i] = {x+w, x-w};
  }

  sort(A, A+n);

  int end = INT_MIN, cnt = 0;
  for (int i=0; i<n; i++) {
    if (A[i].second >= end) {
      end = A[i].first;
      cnt++;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
