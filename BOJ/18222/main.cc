#include <bits/stdc++.h>
using namespace std;

int popcount(long long x) {
  return __builtin_popcount(x) + __builtin_popcount(x>>32);
}

int main() {
  long long k; cin >> k;
  cout << popcount(k-1) % 2 << endl;
  return 0;
}
