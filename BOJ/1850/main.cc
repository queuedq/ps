#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int main() {
  lld A, B; cin >> A >> B;
  lld g = gcd(A, B);
  string S(g, '1');
  cout << S << endl;
  return 0;
}
