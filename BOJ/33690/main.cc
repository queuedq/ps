#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  int cnt = 1;
  for (int d=1; d<=9; d++) {
    lld x = d;
    while (x <= N) {
      cnt++;
      x = x * 10 + d;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
