#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e7;
const int MW = 1010;
const int MN = 10101;
int W, H, N, dir[MN];
string S;
vector<lld> D, E;
lld ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> W >> H >> N >> S;

  dir[0] = (S[0] == 'L' ? 0 : 1);
  for (int i=1; i<=N; i++) {
    dir[i] = dir[i-1] + (S[i-1] == 'L' ? 1 : 3);
    dir[i] %= 4;
  }
  
  D.assign(W+1, 0);
  E.assign(W+1, 0);
  D[0] = 1;

  for (int i=0; i<=N; i++) {
    if (dir[i] == 0) { // right
      E[0] = 0;
      for (int j=1; j<=W; j++) E[j] = (E[j-1] + D[j-1]) % MOD;
      swap(D, E);
    }

    if (dir[i] == 2) { // left
      E[W] = 0;
      for (int j=W-1; j>=0; j--) E[j] = (E[j+1] + D[j+1]) % MOD;
      swap(D, E);
    }
  }

  ans = D[W];

  D.assign(H+1, 0);
  E.assign(H+1, 0);
  D[0] = 1;

  for (int i=0; i<=N; i++) {
    if (dir[i] == 1) { // up
      E[0] = 0;
      for (int j=1; j<=H; j++) E[j] = (E[j-1] + D[j-1]) % MOD;
      swap(D, E);
    }

    if (dir[i] == 3) { // down
      E[H] = 0;
      for (int j=H-1; j>=0; j--) E[j] = (E[j+1] + D[j+1]) % MOD;
      swap(D, E);
    }
  }

  ans = (ans * D[H]) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
