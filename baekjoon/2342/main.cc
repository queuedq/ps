#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 100'005;
int N, D[MN][5][5];

int move(int s, int e) {
  if (s == 0) return 2;
  if (s == e) return 1;
  if (s%2 == e%2) return 4;
  return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int a=0; a<5; a++) fill(D[0][a], D[0][a]+5, INF);
  D[0][0][0] = 0;

  int i = 0;
  while (true) {
    int x; cin >> x;
    if (x == 0) break;
    i++;

    for (int a=0; a<5; a++) fill(D[i][a], D[i][a]+5, INF);

    for (int a=0; a<5; a++) {
      if (a == x) continue;
      for (int b=0; b<5; b++) {
        D[i][a][x] = D[i][x][a] = min(D[i][a][x], D[i-1][a][b] + move(b, x));
      }
    }
  }

  int ans = INF;
  for (int a=0; a<5; a++) {
    for (int b=0; b<5; b++) ans = min(ans, D[i][a][b]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
