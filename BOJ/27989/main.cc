#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
lld N, A[ST], seg[ST*2];
vector<lld> xs;

int compress(lld x) {
  return lower_bound(all(xs), x) - xs.begin();
}

void upd(int i, lld v) {
  i += ST;
  seg[i] = max(seg[i], v);
  for (i/=2; i>0; i/=2) seg[i] = max(seg[i*2], seg[i*2+1]);
}

lld qry(int l, int r) {
  lld res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res = max(res, seg[l++]);
    if (r&1) res = max(res, seg[--r]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    xs.push_back(A[i]);
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  lld ans = 0;
  for (int i=0; i<N; i++) {
    int h = compress(A[i]);
    lld cost = qry(0, h-1) + A[i];
    upd(h, cost);
    ans = max(ans, cost);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
