#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
lld L, K, C, X[MN], cut;

bool check(lld m) {
  lld len = 0, cnt = 0;
  for (int i=K; i>=0; i--) {
    if (X[i+1] - X[i] > m) return false;

    len += X[i+1] - X[i];
    if (len > m) {
      len = X[i+1] - X[i];
      cnt++;
    }
  }
  if (cnt < C) cut = X[1];
  else cut = len;
  return cnt <= C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> K >> C;
  for (int i=1; i<=K; i++) cin >> X[i];
  sort(X+1, X+K+1);
  X[K+1] = L;

  lld l=0, r=L;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }
  check(r);
  cout << r << ' ' << cut << endl;

  ////////////////////////////////
  return 0;
}
