#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S; cin >> S;
  reverse(all(S));
  int N = sz(S);

  lld cnt = 0, sum = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == '1') {
      sum += i-cnt;
      cnt++;
    }
  }

  cout << (sum % 3 == 0 ? "Bob" : "Alice") << endl;

  ////////////////////////////////
  return 0;
}
