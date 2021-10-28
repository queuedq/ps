#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
const int ST = 1<<19;
lld N, M, K, P[MN], seg[ST*2];
vector<int> S[MN];
int L[MN], R[MN];
vector<int> mid[MN];

struct Query { lld l, r, a; };
Query Q[MN];

void upd(int l, int r, lld v) {
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) seg[l++] += v;
    if (r&1) seg[--r] += v;
  }
}

lld qry(int i) {
  lld res = 0;
  for (i+=ST; i>0; i/=2) res += seg[i];
  return res;
}

lld sum(int i) {
  lld res = 0;
  for (auto s: S[i]) {
    res += qry(s);
    if (res >= P[i]) break;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) { int o; cin >> o; S[o].push_back(i); }
  for (int i=1; i<=N; i++) cin >> P[i];

  cin >> K;
  for (int i=1; i<=K; i++) cin >> Q[i].l >> Q[i].r >> Q[i].a;

  for (int i=1; i<=N; i++) {
    L[i] = 0, R[i] = K+1;
    mid[(K+1)/2].push_back(i);
  }
  for (int t=0; t<20; t++) {
    fill(seg, seg+ST*2, 0);
    for (int m=1; m<=K; m++) {
      if (Q[m].l <= Q[m].r) upd(Q[m].l, Q[m].r, Q[m].a);
      else { upd(Q[m].l, M, Q[m].a); upd(1, Q[m].r, Q[m].a); }

      for (auto i: mid[m]) {
        if (sum(i) >= P[i]) R[i] = m;
        else L[i] = m;
      }
      mid[m].clear();
    }
    for (int i=1; i<=N; i++) mid[(L[i]+R[i])/2].push_back(i);
  }

  for (int i=1; i<=N; i++) {
    if (R[i] > K) cout << "NIE" << endl;
    else cout << R[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
