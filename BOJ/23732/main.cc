#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, ans;
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  int j = 0;
  for (int i=0; i<N; i++) {
    if (i != 0 && S[i] == S[i-1]) j = i;
    ans += j;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
