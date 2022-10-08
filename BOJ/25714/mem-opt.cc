#include <iostream>
using namespace std;
using lld = long long;

const lld MOD = 1e9+7;
lld N, D[2][4]; // D[i][k] -- i floors, k components

int main() {
  cin >> N;
  D[3&1][1] = 1; // 3
  D[3&1][2] = 2; // 1 2 / 2 1
  D[3&1][3] = 1; // 1 1 1
  for (int i=4; i<=N-1; i++) {
    // add to end or merge
    D[i&1][1] = (D[~i&1][1] * 2 + D[~i&1][2]) % MOD;
    D[i&1][2] = (D[~i&1][2] * 4 + D[~i&1][3] * 2) % MOD;
    D[i&1][3] = (D[~i&1][3] * 6) % MOD;
  }
  cout << (D[~N&1][1] * N) % MOD << endl;
  return 0;
}
