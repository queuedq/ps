#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 305;
lld N, D[MAXN];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
  }
  cout << D[N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  D[3] = 0;
  D[4] = 1;

  for (int i=5; i<MAXN; i++) {
    D[i] = D[(i+1)/2]+2;
  }

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << endl;
    solve();
  }

  ////////////////////////////////
  return 0;
}
