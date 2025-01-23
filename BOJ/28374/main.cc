#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// - Color columns black/white alternatingly
// - Choose columns with odd number of free cells
// - They must be matched with different colored column through horizontal bricks
// - Draw a splitting vertical line; By calculating |(black odd cols) - (white odd cols)| on one side,
//   we get how much horizontal bricks should pass the splitting line
// - Calculate number of cells occupied by horizontal bricks in each column
// - Put all these bricks at the top

const int MW = 202020;
int H, W, A[MW], need[MW];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> W >> H;
  for (int i=0; i<W; i++) cin >> A[i];

  int diff = 0; // (black odd cols) - (white odd cols)
  for (int i=0; i<W; i++) {
    if ((H-A[i])%2 == 1) {
      (i%2 == 0) ? diff++ : diff--;
    }
    need[i] += abs(diff);
    need[i+1] += abs(diff);
  }

  // check if columns are matchable
  if (diff != 0) return cout << "impossible" << endl, 0;

  // check if there is enough space
  for (int i=0; i<W; i++) {
    if (A[i] + need[i] > H) return cout << "impossible" << endl, 0;
  }

  cout << "possible" << endl;

  ////////////////////////////////
  return 0;
}
