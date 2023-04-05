#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve(int test) {
  cout << "Case #" << test << ":" << endl;

  int R, C; cin >> R >> C;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) cout << (i == 0 && j == 0 ? ".." : "+-");
    cout << "+" << endl;
    for (int j=0; j<C; j++) cout << (i == 0 && j == 0 ? ".." : "|.");
    cout << "|" << endl;
  }
  for (int j=0; j<C; j++) cout << "+-";
  cout << "+" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
