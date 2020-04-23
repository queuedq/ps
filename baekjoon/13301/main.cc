#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld fib[81];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fib[0] = fib[1] = 1;
  for (int i=2; i<=80; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  int N; cin >> N;
  cout << fib[N-1]*2 + fib[N]*2 << endl;

  ////////////////////////////////
  return 0;
}
