#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
unordered_map<int, bool> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int a, b; cin >> a >> b;
  int cnt = 0;

  for (int i=0; i<a; i++) {
    int x; cin >> x;
    A[x] = true;
    cnt++;
  }

  for (int i=0; i<b; i++) {
    int x; cin >> x;
    if (A[x]) cnt--;
    else cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
