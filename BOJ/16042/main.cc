#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string S;
int N, D[17][1<<16];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> S;
  int N = S.size();
  D[0][stoi(S, 0, 2)] = 1;
  if (D[0][(1<<N) - 1]) { cout << 0 << endl; return 0; }
  
  for (int i=1; i<=N; i++) {
    int mask = (1<<N) - (1<<(N-i));
    for (int s=0; s<1<<N; s++) {
      if (!D[i-1][s]) continue;
      for (int j=0; j<=N; j++) {
        D[i][s ^ mask>>j] = 1;
      }
    }
    if (D[i][(1<<N) - 1]) { cout << i << endl; return 0; }
  }

  ////////////////////////////////
  return 0;
}
