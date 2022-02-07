#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int ST = 1<<17;
const int INF = 1e9;
int M, N, x[MN], c[MN], s[MN], D[MN];

struct RMQ {
  int seg[ST*2];

  void update(int i, int v) {
    seg[i+=ST] = v;
    for (i/=2; i>0; i/=2) seg[i] = min(seg[i*2], seg[i*2+1]);
  }

  int query(int l, int r) {
    int res = INF;
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) res = min(res, seg[l++]);
      if (r&1) res = min(res, seg[--r]);
    }
    return res;
  }
} rmq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=0; i<N; i++) cin >> x[i];
  for (int i=0, t=0; i<N; i++) {
    cin >> c[i];
    if (c[i] != c[t]) t = i;
    s[i] = t; // start of same color group
  }

  for (int i=0; i<N; i++) {
    if (s[i] == 0) { D[i] = 1; rmq.update(i, 1); continue; }
    D[i] = INF;
    
    // current group
    if (s[i] != i) D[i] = min(D[i], rmq.query(s[i], i-1) + 1);

    int lx = x[s[i]-1] - (x[i] - x[s[i]-1]);
    int rx = x[s[i]] - (x[i] - x[s[i]]);
    // within previous group
    lx = max(lx, x[s[s[i]-1]]);
    rx = min(rx, x[s[i]-1]);
    
    int l = lower_bound(x, x+N, lx) - x;
    int r = upper_bound(x, x+N, rx) - x - 1;
    
    D[i] = min(D[i], rmq.query(l, r) + 1);

    rmq.update(i, D[i]);
  }

  cout << *min_element(D + s[N-1], D + N) << endl;

  ////////////////////////////////
  return 0;
}
