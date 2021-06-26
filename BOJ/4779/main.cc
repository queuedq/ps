#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int pow3[13];

void solve(int n) {
  if (n == 0) { cout << '-'; return; }
  solve(n-1);
  for (int i=0; i<pow3[n-1]; i++) cout << ' ';
  solve(n-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  pow3[0] = 1;
  for (int i=1; i<12; i++) pow3[i] = pow3[i-1] * 3;
  
  int N;
  while (cin >> N) {
    solve(N);
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
