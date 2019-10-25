#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
#define MAX_N 2000000
#define MAX_K 500000
#define B_BITS 100
#define PRE 500000

lld N, K, A[MAX_N];
lld B[MAX_N];
lld pow_10[B_BITS], ones[B_BITS];
lld prePow10[PRE], preOnes[PRE];

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

  prePow10[0] = 1;
  preOnes[0] = 0;
  for (int i = 1; i < PRE; i++) {
    prePow10[i] = (prePow10[i - 1] * 10) % K;
    preOnes[i] = (preOnes[i - 1] * 10 + 1) % K;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  input();
  init();
  lld result = 0;
  for (int i = 0; i < N; i++) {
    lld mask = 1L << 62;
    lld bit = 62;
    while (mask >= PRE / 2) {
      if (B[i] & mask) {
        result = (result * pow_10[bit] + A[i] * ones[bit]) % K;
      }
      mask >>= 1;
      bit -= 1;
    }
    B[i] = B[i] & ((mask << 1) - 1);
    result = (result * prePow10[B[i]] + A[i] * preOnes[B[i]]) % K;
  }
  cout << result << endl;
  return 0;
}
