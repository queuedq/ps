#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, A[MN];

void solve() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  sort(A+1, A+N+1);

  vector<int> B = {0}; // zig-zag moves
  for (int i=1; i<=N; i++) {
    if (A[i] > A[i-1]) {
      B.push_back(A[i] - A[i-1]);
      B.push_back(1);
    } else {
      B.back()++;
    }
  }

  reverse(all(B));
  int win = 0;
  for (auto x: B) {
    if (x > 1) win = 1;
    else if (x == 1) win = !win;
  }

  if (win) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
