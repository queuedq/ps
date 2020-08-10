#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 155;
const int MOD = 9901;
int N;
bool adj[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<N; j++) {
      adj[i][j] = (s[j] == '1');
    }
  }

  int ans = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
      for (int k=0; k<j; k++) {
        int ij = 0, jk = 0, ki = 0, c = 0;
        for (int l=0; l<N; l++) {
          if (l == i || l == j || l == k) continue;
          if (adj[l][i] && adj[l][j]) ij++;
          if (adj[l][j] && adj[l][k]) jk++;
          if (adj[l][k] && adj[l][i]) ki++;
          if (adj[l][i] && adj[l][j] && adj[l][k]) c++;
        }
        ans = (ans + ij*jk*ki - c*(jk+ki+ij) + 2*c) % MOD;
      }
    }
  }

  ans = (ans + MOD) % MOD;
  cout << (ans%2==0 ? ans/2 : (ans+MOD)/2) << endl;

  ////////////////////////////////
  return 0;
}
