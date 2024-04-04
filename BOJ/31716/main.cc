#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
 
////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, K;
char A[2][MN];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
 
  cin >> N >> K;
  cin >> A[0] >> A[1];
 
  // find initial y
  int y = 0;
  for (int i=0; i<N; i++) {
    if (A[0][i] == '#') { y = 1; break; }
    if (A[1][i] == '#') { y = 0; break; }
  }
  if (A[y][0] == '#') { cout << -1 << '\n'; return 0; }
 
  int init_y = y;
 
  // simulate
  lld ans = 0;
  for (int i=0; i<N; i++) {
    if (A[y][i] == '#') {
      if (A[!y][i-1] == '#' || A[!y][i] == '#') { cout << -1 << '\n'; return 0; }
      y = !y;
      ans++;
    }
    ans++;
  }
 
  // ans
  if (K == 1) {
    cout << ans - 1 << endl;
  } else if (y == init_y) {
    cout << ans*K - 1 << endl;
  } else {
    if (A[y][0] == '#' && A[!y][N-1] == '#') { cout << -1 << '\n'; return 0; }
    cout << (ans+1)*K - 2 << endl;
  }
 
  ////////////////////////////////
  return 0;
}
