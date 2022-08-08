#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, M, pos[ST], seg[ST*2];

void add(int i, int v) {
  seg[i+=ST] += v;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int sum(int l, int r) {
  int ans = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) ans += seg[l++];
    if (r&1) ans += seg[--r];
  }
  return ans;
}

void solve() {
  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    pos[i] = N-i+1;
    add(pos[i], 1);
  }
  for (int i=N+1; i<=N+M; i++) {
    int x; cin >> x;
    cout << sum(pos[x]+1, ST-1) << ' ';
    add(pos[x], -1);
    pos[x] = i;
    add(pos[x], 1);
  }
  cout << endl;

  // reset
  for (int i=1; i<=N; i++) add(pos[i], -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
