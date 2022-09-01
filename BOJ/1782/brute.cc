#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld A, B, ans;
int rev[10];

lld mirror(lld x, bool odd) {
  lld l = odd ? x/10 : x, r = 0;
  while (x) {
    r = r*10 + rev[x%10];
    l *= 10;
    x /= 10;
  }
  return l+r;
}

void solve(int len, bool msd, lld num) {
  if (len <= 0) {
    lld x = mirror(num, len < 0);
    if (A <= x && x <= B) ans++;
    return;
  }
  
  vector<int> digits = {0, 1, 2, 5, 8};
  if (len == 1) digits = {0, 1, 8};
  else if (msd) digits = {1, 2, 5, 8}; // allow 0 if len=1 and msd

  for (int d: digits) {
    solve(len-2, 0, num*10 + d);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  rev[0] = 0; rev[1] = 1; rev[2] = 5; rev[5] = 2; rev[8] = 8;

  cin >> A >> B;
  for (int len=1; len<=18; len++) solve(len, 1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
