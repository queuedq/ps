#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, pre[MAXN], in[MAXN];

void solve(int pl, int pr, int il, int ir) {
  if (pr-pl < 0) return;
  int i;
  for (i = il; i <= ir; i++) {
    if (pre[pl] == in[i]) break;
  }
  solve(pl+1, pl+(i-il), il, i-1);
  solve(pl+(i-il)+1, pr, i+1, ir);
  cout << pre[pl] << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> pre[i];
    for (int i=0; i<N; i++) cin >> in[i];
    solve(0, N-1, 0, N-1);
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
