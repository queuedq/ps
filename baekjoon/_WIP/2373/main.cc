#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1000;
int N;
bool D[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=1; i<=N; i++) {
    cout << i/10 << i%10 << " ";
    for (int j=1; j<=i; j++) {
      D[i][j] = true;
      for (int t=1; t <= j*2 && t <= i-j; t++) {
        if (D[i-j][t]) D[i][j] = false;
      }
      cout << D[i][j];
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
