#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 155;
lld N, P, F[MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P;
  F[0] = 1, F[1] = 2;
  for (int a=2; a<=N; a++) F[a] = (F[a-1] + F[a-2]) % P;

  D[0][0] = 1;
  for (int a=1; a<=N; a++) {
    for (int x=1; x<=a; x++) {
      for (int y=1; y<=x; y++) {
        for (int b=y; b<=a; b++) {
          D[a][x] += (D[a-b][x-y] * D[b-y][y-1]) % P * F[y];
          D[a][x] %= P;
        }
      }
    }
  }

  lld sum = 0;
  for (int x=1; x<=N; x++) sum = (sum + D[N][x]) % P;
  cout << sum << endl;

  ////////////////////////////////
  return 0;
}
