#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
const int MN = 2020;
int N, L, D[MN][MN];
vector<int> dv[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;

  for (int i=1; i<=N; i++) {
    for (int j=i; j<=N; j+=i) {
      dv[j].push_back(i);
    }
  }
  
  D[0][1] = 1;
  for (int i=1; i<=L; i++) {
    for (int j=1; j<=N; j++) {
      for (auto d: dv[j]) {
        D[i][j] = (D[i][j] + D[i-1][d]) % MOD;
      }
    }
  }

  int ans = 0;
  for (int j=1; j<=N; j++) ans = (ans + D[L][j]) % MOD;

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
