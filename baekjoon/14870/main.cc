#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1505;
const int ST = 1<<11;
lld N, A[MN][MN], D[MN][MN], tot = 0;
lld seg[MN][ST*2];

lld seg_query(int i, int j) {
  lld res = 0;
  for (int n=ST+j; n>0; n/=2) res += seg[i][n];
  return res;
}

void seg_update(int i, int l, int r, lld v) {
  for (l+=ST, r+=ST; l <= r; l/=2, r/=2) {
    if (l & 1) seg[i][l++] += v;
    if (~r & 1) seg[i][r--] += v;
  }
}

lld process_query(int i, int j, lld v) {
  int l = j, r = j+1;

  while (r <= N) {
    lld L = seg_query(i, r-1);
    lld U = seg_query(i-1, r);
    if (max(L, U) == max(L+v, U)) break;
    r++;
  }
  seg_update(i, l, r-1, v);
  tot += v * (r-l);

  for (i++; i<=N; i++) {
    while (l < r) {
      lld L = seg_query(i, l-1);
      lld U = seg_query(i-1, l) - v; // Already updated
      if (max(L, U) != max(L, U+v)) break;
      l++;
    }
    if (l == r) break;
    while (r <= N) {
      lld L = seg_query(i, r-1);
      lld U = seg_query(i-1, r);
      if (max(L, U) == max(L+v, U)) break;
      r++;
    }
    seg_update(i, l, r-1, v);
    tot += v * (r-l);
  }

  return tot;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      cin >> A[i][j];

      D[i][j] = max(D[i-1][j], D[i][j-1]) + A[i][j];
      seg_update(i, j, j, D[i][j]);
      tot += D[i][j];
    }
  }

  cout << tot << endl;
  for (int i=1; i<=N; i++) {
    char c; int v, x, y; cin >> c >> x >> y;
    v = c == 'U' ? 1 : -1;
    cout << process_query(x, y, v) << endl;
  }

  ////////////////////////////////
  return 0;
}
