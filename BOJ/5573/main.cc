#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MW = 1010;
int H, W, A[MW][MW], D[MW][MW], N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> H >> W >> N;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) cin >> A[i][j];
  }

  D[0][0] = N-1;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int fst, snd;
      fst = D[i][j] - D[i][j]/2;
      snd = D[i][j]/2;
      if (A[i][j] == 0) D[i+1][j] += fst, D[i][j+1] += snd;
      else D[i][j+1] += fst, D[i+1][j] += snd;
    }
  }

  int i=0, j=0;
  while (i<H && j<W) {
    if ((A[i][j] + D[i][j]) % 2 == 0) i++;
    else j++;
  }
  cout << i+1 << " " << j+1 << endl;

  ////////////////////////////////
  return 0;
}
