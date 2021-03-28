#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 2e5 + 5;
const int P = 998244353;
int N, Q;
lld a[MAX_N], b[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i = N; i >= 0; i--) {
    cin >> a[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < Q; i++) {
    lld val = 0;
    for (int k = N; k >= 0; k--) {
      val *= b[i];
      val += a[k];
      val = val % P;
    }
    cout << val << endl;
  }

  ////////////////////////////////
  return 0;
}
