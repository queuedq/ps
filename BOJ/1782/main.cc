#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld A, B, D[20][20][2][2];
int rev[10];
vector<lld> num;

lld dp(int len, int i, bool eq, bool rl) { // eq: left half eq, rl: right half leq
  lld &res = D[len][i][eq][rl];
  if (res) return res;
  if (i == (len+1)/2) return res = !eq || rl;

  vector<int> digits = {0, 1, 2, 5, 8};
  if (i*2+1 == len) digits = {0, 1, 8}; // center: self-symmetric
  int lmt = 9;
  if (eq) lmt = num[i];

  for (auto d: digits) {
    if (d > lmt) break;
    if (i == 0 && d == 0) continue;

    int neq = eq && d == num[i];
    int nrl = (rev[d] == num[len-1-i] && rl) || rev[d] < num[len-1-i];
    res += dp(len, i+1, neq, nrl);
  }
  return res;
}

lld solve(lld x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  num.clear();
  while (x) { num.push_back(x%10); x /= 10; }
  reverse(all(num));

  memset(D, 0, sizeof D);
  lld res = dp(sz(num), 0, 1, 1);
  for (int len=sz(num)-1; len>=1; len--) res += dp(len, 0, 0, 1);
  res += 1; // 0
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  rev[0] = 0; rev[1] = 1; rev[2] = 5; rev[5] = 2; rev[8] = 8;

  cin >> A >> B;
  cout << solve(B) - solve(A-1) << endl;

  ////////////////////////////////
  return 0;
}
