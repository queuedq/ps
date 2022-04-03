#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int C[3], M[3], Y[3], K[3], D = 1e6;

void solve(int test) {
  for (int i=0; i<3; i++) cin >> C[i] >> M[i] >> Y[i] >> K[i];
  int c = min({C[0], C[1], C[2]});
  int m = min({M[0], M[1], M[2]});
  int y = min({Y[0], Y[1], Y[2]});
  int k = min({K[0], K[1], K[2]});

  cout << "Case #" << test << ": ";
  if (c+m+y+k < D) cout << "IMPOSSIBLE" << endl;
  else if (c+m+y < D) cout << c << " " << m << " " << y << " " << (D -c-m-y) << endl;
  else if (c+m < D) cout << c << " " << m << " " << (D -c-m) << " " << 0 << endl;
  else if (c < D) cout << c << " " << (D -c) << " " << 0 << " " << 0 << endl;
  else cout << D << " " << 0 << " " << 0 << " " << 0 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
