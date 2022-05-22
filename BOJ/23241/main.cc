#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int XM = 2020;
const int ST = 1<<11;
const lld INF = LLONG_MAX;
lld N, M, D[XM][XM], seg[XM][ST*2];
vector<lld> xs;

struct Interval {
  lld l, r, c;
  bool operator <(const Interval &I) const { return r < I.r; }
};
Interval I[XM];

void build(int i) {
  fill(seg[i], seg[i]+ST*2, INF);
  for (int j=0; j<=M; j++) seg[i][ST+j] = D[i][j];
  for (int j=ST-1; j>0; j--) seg[i][j] = min(seg[i][j*2], seg[i][j*2+1]);
}

lld qry(int i, int l, int r) {
  lld ans = INF;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) ans = min(ans, seg[i][l++]);
    if (r&1) ans = min(ans, seg[i][--r]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  xs.resize(N);
  for (int i=0; i<N; i++) cin >> xs[i];
  sort(all(xs));

  for (int i=1; i<=M; i++) {
    lld l, r, c; cin >> l >> r >> c;
    l = lower_bound(all(xs), l) - xs.begin();
    r = upper_bound(all(xs), r) - xs.begin() - 1;
    I[i] = {l, r, c};
  }
  I[0] = {0, -1, 0};
  sort(I+1, I+M+1);

  for (int i=1; i<=M; i++) fill(D[i], D[i]+M+1, INF);

  lld ans = INF;
  for (int i=1; i<=M; i++) {
    D[i][0] = I[i].l == 0 ? I[i].c : INF;

    for (int j=1; j<i; j++) {
      if (I[j].r < I[i].l-1 || I[i].l <= I[j].l) continue;
      lld c = (I[j].r == I[i].l-1) ? max(I[i].c, I[j].c) : I[i].c + I[j].c;      

      int a = lower_bound(I, I+M+1, (Interval){0, I[j].l-1, 0}) - I;
      int b = upper_bound(I, I+M+1, (Interval){0, I[i].l-1, 0}) - I - 1;
      D[i][j] = max(qry(j, a, b), c);
    }
    
    build(i);
    if (I[i].r == N-1) ans = min(ans, seg[i][1]);
  }

  cout << (ans < INF ? ans : -1) << endl;

  ////////////////////////////////
  return 0;
}
