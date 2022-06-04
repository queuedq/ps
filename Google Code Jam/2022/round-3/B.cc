#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, C, A[ST], B[ST], P[ST];
vector<int> idx[ST]; // indicies of color
int st[ST]; // starting index (updated by sweeping)

int seg[2][ST*2]; // not-ok ranges

void update(int n, int nl, int nr, int l, int r, int v) {
  if (r < nl || nr < l) return;
  if (l <= nl && nr <= r) {
    seg[0][n] += v;
  } else {
    int m = (nl+nr+1)/2;
    update(n*2, nl, m-1, l, r, v);
    update(n*2+1, m, nr, l, r, v);
  }
  if (seg[0][n] != 0) seg[1][n] = nr-nl+1;
  else if (n < ST) seg[1][n] = seg[1][n*2] + seg[1][n*2+1];
  else seg[1][n] = 0;
}
void update(int l, int r, int v) {
  // cout << "update [" << l << "," << r << "] " << v << endl;
  update(1, 0, ST-1, l, r, v);
}

int query(int n, int nl, int nr, int l, int r) {
  if (r < nl || nr < l) return 0;
  if (nl == l && r == nr) return seg[1][n];
  // assert(nl <= l && r <= nr); // should be true because we split the range [l, r]
  if (seg[0][n]) return r-l+1; // covered
  int m = (nl+nr+1)/2;
  return query(n*2, nl, m-1, l, min(m-1, r)) + query(n*2+1, m, nr, max(m, l), r);
}
int query(int l, int r) { return query(1, 0, ST-1, l, r); }

void reset() {
  fill(seg[0], seg[0]+ST*2, 0);
  fill(seg[1], seg[1]+ST*2, 0);
  for (int i=1; i<=C; i++) idx[i].clear();
}

void solve(int test) {
  cin >> N >> C;
  for (int i=1; i<=C; i++) cin >> A[i] >> B[i];
  for (int i=0; i<N; i++) {
    cin >> P[i]; P[i+N] = P[i];
    idx[P[i]].push_back(i);
    idx[P[i]].push_back(i+N);
  }
  for (int i=1; i<=C; i++) sort(all(idx[i]));
  fill(st+1, st+C+1, 0);

  lld ans = 0;

  // init segtree
  for (int c=1; c<=C; c++) {
    if (idx[c].empty()) continue;
    if (A[c] > 0) {
      if (A[c]-1 < idx[c].size())
        update(idx[c][0], idx[c][A[c]-1]-1, 1);
      else
        update(idx[c][0], ST-1, 1);
    }
    if (B[c] < idx[c].size())
      update(idx[c][B[c]], ST-1, 1);
  }
  ans += N-2 - query(1, N-2);
  // cout << "i=0" << " " << ans << endl;

  // sweep
  for (int i=1; i<N; i++) {
    int c = P[i-1];

    if (A[c] > 0) {
      if (st[c] + A[c]-1 < idx[c].size())
        update(idx[c][st[c]], idx[c][st[c] + A[c]-1]-1, -1);
      else
        update(idx[c][st[c]], ST-1, -1);
    }
    if (st[c]+B[c] < idx[c].size())
      update(idx[c][st[c] + B[c]], ST-1, -1);

    st[c]++;

    if (A[c] > 0) {
      if (st[c] + A[c]-1 < idx[c].size())
        update(idx[c][st[c]], idx[c][st[c] + A[c]-1]-1, 1);
      else
        update(idx[c][st[c]], ST-1, 1);
    }
    if (st[c] + B[c] < idx[c].size())
      update(idx[c][st[c] + B[c]], ST-1, 1);

    int x = N-2 - query(i+1, i+N-2);
    ans += x;
    // cout << "i=" << i << " " << x << endl;
  }

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
