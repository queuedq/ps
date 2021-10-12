#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 155;
int N, A[MN], K;
bitset<MN*MN/2 * 100> D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> K;
  if (K > (N+1)*N/2 * 100) { cout << K << endl; return 0; }

  D[0][0] = 1;
  for (int i=1; i<=N; i++) {
    D[i] = D[i-1];
    int sum = 0;
    for (int j=1; j<=i; j++) {
      sum += A[i-j+1] * j;
      D[i] |= D[max(i-j-1, 0)] << sum;
    }
  }

  for (int i=K; ; i++) {
    if (D[N][i] == 0) { cout << i << endl; return 0; }
  }

  ////////////////////////////////
  return 0;
}
