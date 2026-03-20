#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2505;
int N, M, vst[MN][MN];
char A[MN][MN];

bool oob(int i, int j) { return i<1 || i>N || j<1 || j>M; }

int chain(int i, int j, int down) {
  int value = 0, p = 0;

  while (!oob(i, j)) {
    char c = A[i][j];

    if (down) {
      if (c == 'X' || c == 'Z' || c == 'P') p = 0;
      else if (c == 'G') value += p;
      else p = !p;
    } else {
      if (c == 'X' || c == 'G' || c == 'D') p = 0;
      else if (c == 'P') value -= p;
      else p = !p;
    }

    if (down) i++;
    else j--;
    down = !down;
  }

  return value;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) cin >> A[i][j];
  }

  int value = 0;
  for (int j=1; j<=M; j++) value += chain(1, j, 0);
  for (int i=1; i<=N; i++) value += chain(i, M, 1);

  if (value > 0) cout << "Scallion" << endl;
  else cout << "Aubergine" << endl;

  ////////////////////////////////
  return 0;
}
