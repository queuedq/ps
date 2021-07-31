#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int ST = 1<<17;
lld N, K, H[MN], A[MN], B[MN], seg[4][ST*2];

void upd(lld seg[], int i, lld v) {
  seg[i += ST] += v;
  for (i /= 2; i > 0; i /= 2) seg[i] = seg[i*2] + seg[i*2+1];
}

lld qry(lld seg[], int l, int r) {
  lld ans = 0;
  for (l += ST, r += ST+1; l < r; l /= 2, r /= 2) {
    if (l&1) ans += seg[l++];
    if (r&1) ans += seg[--r];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> H[i];
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> B[i];

  for (int i=0; i<K; i++) {
    upd(seg[0], H[i], A[i]);
    upd(seg[1], H[i], B[i]);
    upd(seg[2], H[i], H[i] * A[i]);
    upd(seg[3], H[i], H[i] * B[i]);
  }

  lld ans = LLONG_MAX;
  for (int i=0; i<N-K+1; i++) {
    int l = 0, r = 101010;
    while (l+1 < r) {
      int m = (l+r) / 2;
      if (qry(seg[0], 0, m) < qry(seg[1], m+1, ST-1)) l = m;
      else r = m;
    }
    lld L = r * qry(seg[0], 0, r) - qry(seg[2], 0, r);
    lld R = qry(seg[3], r+1, ST-1) - r * qry(seg[1], r+1, ST-1);
    ans = min(ans, L+R);

    upd(seg[0], H[i], -A[i]);
    upd(seg[1], H[i], -B[i]);
    upd(seg[2], H[i], -H[i] * A[i]);
    upd(seg[3], H[i], -H[i] * B[i]);
    
    upd(seg[0], H[i+K], A[i+K]);
    upd(seg[1], H[i+K], B[i+K]);
    upd(seg[2], H[i+K], H[i+K] * A[i+K]);
    upd(seg[3], H[i+K], H[i+K] * B[i+K]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
