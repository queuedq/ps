#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
#define MAX_N 2000000
#define MAX_K 500000
#define B_BITS 100

lld N, K, A[MAX_N];
lld B[MAX_N];
lld pow_10[B_BITS], ones[B_BITS];

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
}

void init() {
  pow_10[0] = 10;
  ones[0] = 1;
  for (int i = 1; i < B_BITS; i++) {
    pow_10[i] = pow_10[i - 1] * pow_10[i - 1] % K;
    ones[i] = ( ones[i - 1] + ones[i - 1] * pow_10[i - 1] ) % K;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  input();
  init();
  lld result = 0;
  for (int i = 0; i < N; i++) {
    int bit = 0;
    while (B[i] > 0) {
      if (B[i] & 1) {
        result = result * pow_10[bit] % K;
        result = ( result + A[i] * ones[bit] ) % K;
      }
      B[i] >>= 1;
      bit += 1;
    }
  }
  cout << result << endl;
  return 0;
}
