#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, L[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> L[i];
    sort(L, L+N);
    
    int mx = 0;
    for (int i=0; i<N; i++) {
      if (i+2 < N) mx = max(mx, L[i+2] - L[i]);
    }
    cout << mx << endl;
  }

  ////////////////////////////////
  return 0;
}
