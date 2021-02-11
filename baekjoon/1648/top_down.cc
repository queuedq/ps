#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 9901;
const int MN = 15;
int N, M, D[MN*MN][1<<MN];

int dp(int i, int state) {
  if (i == N*M) return state == 0;
  if (D[i][state] != -1) return D[i][state];

  D[i][state] = 0;

  if (state & 1) // occupied
    D[i][state] += dp(i+1, state >> 1);

  if ((state & 1) == 0) // vertical
    D[i][state] += dp(i+1, state >> 1 | 1 << M-1);

  if (i%M != M-1 && (state & 3) == 0) // horizontal
    D[i][state] += dp(i+1, state >> 1 | 1);

  return D[i][state] = D[i][state] % MOD;;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N*M; i++) fill(D[i], D[i] + (1<<M), -1);
  cout << dp(0, 0) << endl;

  ////////////////////////////////
  return 0;
}
