#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

bool win(lld a, lld b) {
  if (a < b) swap(a, b);
  if (b == 0) return false;
  if (a / b > 1) return true;
  return !win(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld a, b; cin >> a >> b;
  cout << (win(a, b) ? "win" : "lose") << endl;

  ////////////////////////////////
  return 0;
}
