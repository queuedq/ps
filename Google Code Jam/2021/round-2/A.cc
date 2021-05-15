#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

void solve(int test) {
  for (int i=1; i<N; i++) {
    cout << "M " << i << " " << N << endl;
    int j; cin >> j;
    if (i != j) {
      cout << "S " << i << " " << j << endl;
      int ok; cin >> ok;
      assert(ok == 1);
    }
  }
  cout << "D" << endl;
  int ok; cin >> ok;
  assert(ok == 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T >> N;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
