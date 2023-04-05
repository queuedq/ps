#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define BIT_LEN 50
int T;
int N;
lld M, A[1000];
lld k[BIT_LEN];

lld g(int bit) {
  lld result = 0;
  for (int i = 0; i < N; i++) {
    result += (A[i] & (1L << bit)) ^ (k[bit] << bit);
  }
  return result;
}

lld f() {
  lld result = 0;
  for (int i = 0; i < BIT_LEN; i++) {
    result += g(i);
  }
  return result;
}

lld calc() {
  // Reset
  for (int i = 0; i < BIT_LEN; i++) {
    k[i] = 0;
  }

  // Input
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < BIT_LEN; i++) {
    lld a = g(i);
    k[i] = 1;
    lld b = g(i);

    if (a < b) { k[i] = 0; }
  }

  lld diff = M - f();
  if (diff < 0) { return -1; }

  for (int i = BIT_LEN - 1; i >= 0; i--) {
    if (k[i] == 1) {
      continue;
    }
    diff += g(i);
    k[i] = 1;
    diff -= g(i);
    if (diff < 0) {
      diff += g(i);
      k[i] = 0;
      diff -= g(i);
    }
  }

  lld result = 0;
  for (int i = 0; i < BIT_LEN; i++) {
    result += k[i] << i;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
