#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int main() {
  lld N, M; cin >> N >> M;
  if (N == 1 || M == 1) return cout << max(N, M) << endl, 0;
  lld g = gcd(N-1, M-1);
  lld n = (N-1)/g, m = (M-1)/g;
  cout << n*m*g+1 - (n-1)*(m-1)/2 << endl;
  return 0;
}
