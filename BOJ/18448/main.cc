#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
const int ST = 1<<18;
int N, K, w[MN], idx[MN], s, seg[ST*2];
vector<int> xs;

void upd(int i, int v) {
  seg[i+=ST] = v;
  for (i/=2; i>0; i/=2) seg[i] = max(seg[i*2], seg[i*2+1]);
}

int qry(int l, int r) {
  int ret = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) ret = max(ret, seg[l++]);
    if (r&1) ret = max(ret, seg[--r]);
  }
  return ret;
}

bool check(int S) {
  fill(seg, seg+ST*2, 0);
  upd(0, 1);
  for (int i=s+1; i!=s; i=(i+1)%N) {
    int r = upper_bound(all(xs), S - w[i]) - xs.begin() - 1;
    if (r >= 0) upd(idx[i], qry(0, r)+1);
  }
  return qry(0, N-1) >= K;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) { cin >> w[i]; xs.push_back(w[i]); }
  sort(all(xs));
  for (int i=0; i<N; i++) idx[i] = lower_bound(all(xs), w[i]) - xs.begin();
  s = min_element(w, w+N) - w;

  lld l = w[s], r = 2e9+5;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << r << endl;

  ////////////////////////////////
  return 0;
}
