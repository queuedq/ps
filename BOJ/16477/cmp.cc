#include "cmp.h"

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int R[4] = {6, 8, 10, 12}; // mixed-radix

void remember(int a) {
  for (int i: {0, 1, 2, 3}) {
    bit_set((a % R[i]) + i*64 + 1);
    a /= R[i];
  }
}

int compare(int b) {
  int d[4] = {0, 0, 0, 0};
  for (int i: {0, 1, 2, 3}) {
    d[i] = b % R[i];
    b /= R[i];
  }

  for (int i: {3, 2, 1, 0}) {
    if (bit_get(d[i] + i*64 + 1)) continue;
    if (d[i] < R[i]/2) {
      for (int e=d[i]-1; e>=0; e--) {
        if (bit_get(e + i*64 + 1)) return 1; // b > a
      }
      return -1; // b < a
    } else {
      for (int e=d[i]+1; e<R[i]; e++) {
        if (bit_get(e + i*64 + 1)) return -1; // b < a
      }
      return 1; // b > a
    }
  }
  return 0; // b = a
}
