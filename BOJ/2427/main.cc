#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using llf = long double;
lld N, P, V;

lld solve(int k) { // k partitioning operations
  lld g = pow((llf)N, (llf)1/k);
  lld x = 1, cost = V*k;
  for (int i=0; i<k; i++) x *= g, cost += P*g;
  while (x < N) x = x/g*(g+1), cost += P;
  return cost;
}

int main() {
  cin >> N >> P >> V;
  if (N == 1) { cout << 0 << endl; return 0; }
  lld ans = LLONG_MAX;
  for (int k=1; k<=100; k++) ans = min(ans, solve(k));
  cout << ans << endl;
  return 0;
}
