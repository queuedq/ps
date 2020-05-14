#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 25;
int N, W[MAXN], ans;

void solve(int i, int w) {
  if (i == N) {
    if (w == (1<<26)-1) ans++;
    return;
  }

  solve(i+1, w);
  solve(i+1, w | W[i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (auto c: s) W[i] = W[i] | (1 << c-'a');
  }

  solve(0, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
