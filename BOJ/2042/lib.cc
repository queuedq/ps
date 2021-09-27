#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;
lld N, M, K, seg[ST*2];

void update(int i, lld val) {
  seg[i+=ST] = val;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

lld query(int l, int r) { // [l, r]
  lld res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    lld x; cin >> x;
    update(i, x);
  }

  for (int i=0; i<M+K; i++) {
    lld a, b, c; cin >> a >> b >> c;
    if (a == 1) update(b, c);
    else cout << query(b, c) << endl;
  }

  ////////////////////////////////
  return 0;
}
