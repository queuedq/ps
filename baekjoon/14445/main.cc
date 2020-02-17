#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N; cin >> N;
  if (N == 1) cout << 0 << "\n";
  else cout << (N%2 ? (N+1)/2 : N/2) << "\n";
  return 0;
}
