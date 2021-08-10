#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int N = 1e5;
int D[N+1], g[16];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(D, D+N+1, -1);

  for (int i=1; i<=N; i++) {
    fill(g, g+16, 0);
    for (int j=2; j<=i-1; j++) {
      if (g[D[j-1] ^ D[i-j]] < 16) g[D[j-1] ^ D[i-j]] = 1;
    }

    D[i] = -1;
    for (int j=0; j<16; j++) {
      if (g[j] == 0) { D[i] = j; break; }
    }
  }

  // Exploration

  int mx = 0;
  for (int i=1; i<=N; i++) mx = max(mx, D[i]);
  cout << mx << endl;
  // mx: 9

  vector<int> zero;
  for (int i=1; i<=N; i++) {
    if (D[i] == 0) zero.push_back(i);
  }
  for (int i=0; i<min((int)zero.size(), 100); i++) {
    cout << zero[i+1] - zero[i] << " ";
  }
  cout << endl;
  // 1 4 4 6 6 4 4 6 4 (4 12 4 4 10) (4 12 4 4 10) (4 12 4 4 10) ...

  for (int i=1; i<=300; i++) {
    cout << D[i];
    if (i % 34 == 0) cout << endl; // 4+12+4+4+10 = 34
  }
  cout << endl;
  // 0011203110332240522330113021104527
  // 4011203110332244552330113021104537
  // 4811203110332244559330113021104537
  // 4811203110332244559330113021104537 ...

  ////////////////////////////////
  return 0;
}

