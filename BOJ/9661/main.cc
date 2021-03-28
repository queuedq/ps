#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld N; cin >> N;
  if (N % 5 == 1) cout << "SK" << endl;
  if (N % 5 == 2) cout << "CY" << endl;
  if (N % 5 == 3) cout << "SK" << endl;
  if (N % 5 == 4) cout << "SK" << endl;
  if (N % 5 == 0) cout << "CY" << endl;

  ////////////////////////////////
  return 0;
}
