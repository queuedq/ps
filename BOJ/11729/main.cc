#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
void hanoi(int N, int s, int e) {
  if (N == 0) return;
  int m = s^e;
  hanoi(N-1, s, m);
  cout << s << " " << e << endl;
  hanoi(N-1, m, e);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  cout << ((1<<N) - 1) << endl;
  hanoi(N, 1, 3);

  ////////////////////////////////
  return 0;
}
