#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int P; cin >> P;
    ans ^= P;
  }
  cout << (ans ? "koosaga" : "cubelover") << endl;

  ////////////////////////////////
  return 0;
}
