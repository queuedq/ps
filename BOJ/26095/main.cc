#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, cnt[MN], used[MN], tot;

bool solve(int x) {
  if (tot > N) return 0;
  if (x <= 1) { tot++; return 1; }

  for (int i=0; i<=x-1; i++) {
    if (used[i] < cnt[i]) { tot++; used[i]++; }
    else solve(i);
  }
  return tot <= N;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) { int x; cin >> x; cnt[x]++; }

  int l = -1, r = N+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    fill(used, used+N, 0);
    tot = 0;

    if (solve(m)) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
