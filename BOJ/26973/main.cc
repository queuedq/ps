#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 5e6+5;
int prime[MX], t[MX];
vector<int> p1, p3;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  p1.push_back(1);
  fill(prime, prime+MX, 1);
  for (int i=2; i<MX; i++) {
    if (prime[i]) {
      for (int j=i*2; j<MX; j+=i) prime[j] = 0;
      if (i%4 == 1) p1.push_back(i);
      if (i%4 == 3) p3.push_back(i);
    }
  }

  for (int i=0; i<MX; i++) {
    if (i%4 == 0) {
      t[i] = i/4;
    } else if (i%4 == 1) {
      int p = *(upper_bound(all(p1), i) - 1);
      t[i] = (i-p)/4;
    } else if (i%4 == 2) {
      t[i] = (i-2)/4;
    } else {
      int p = *(upper_bound(all(p3), i) - 1);
      t[i] = (i-p)/4;
    }
  }

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    pii win = {INT_MAX, 0};
    pii lose = {INT_MAX, 0};
    for (int i=0; i<N; i++) {
      int a; cin >> a;
      if (a%4 == 0) lose = min(lose, {t[a], i});
      else win = min(win, {t[a], i});
    }
    if (win < lose) cout << "Farmer John" << endl;
    else cout << "Farmer Nhoj" << endl;
  }

  ////////////////////////////////
  return 0;
}
