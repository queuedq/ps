#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 100005
#define MOD 1000000007
lld N, M, F[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  F[1] = 1;
  F[2] = 2;
  for (int i = 3; i <= MAX_N; i++) {
    F[i] = (F[i - 1] + F[i - 2]) % MOD;
  }

  cin >> N >> M;
  cout << (2 * (F[N] + F[M]) - 2) % MOD << endl;

  ////////////////////////////////
  return 0;
}
