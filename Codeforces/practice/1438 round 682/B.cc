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

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    set<int> B;
    for (int i=0; i<N; i++) {
      int b; cin >> b;
      B.insert(b);
    }
    cout << (B.size() < N ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
