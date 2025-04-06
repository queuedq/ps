#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld A, B;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> A >> B;

  int cnt = 0;
  while (A < B) A /= 2, B /= 2, cnt++;

  lld X = (A << cnt) + (1LL << (cnt-1));
  cout << (X-1) << " " << X << endl;

  ////////////////////////////////
  return 0;
}
