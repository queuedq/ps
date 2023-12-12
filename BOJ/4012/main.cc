#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, nxt[MN*2][20];
vector<int> xs;

struct Interval {
  int s, e;
  bool operator<(const Interval &I) const { return pii(s, e) < pii(I.s, I.e); }
};
Interval I[MN];

int compress(int x) {
  return lower_bound(all(xs), x) - xs.begin();
}

int query(int s, int e) {
  int res = 0;
  for (int t=19; t>=0; t--) {
    if (nxt[s][t] > e) continue;
    s = nxt[s][t];
    res += 1<<t;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int s, e; cin >> s >> e;
    I[i] = {s, ++e};
    xs.push_back(s);
    xs.push_back(e);
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (int i=0; i<N; i++) {
    I[i].s = compress(I[i].s);
    I[i].e = compress(I[i].e);
  }

  // build sparse table
  vector<Interval> tmp(N);
  for (int i=0; i<N; i++) tmp[i] = I[i];
  sort(all(tmp));

  int X = sz(xs);
  for (int i=N-1, k=X-1, mn=X; k>=0; k--) {
    while (i >= 0 && tmp[i].s >= k) {
      mn = min(mn, tmp[i].e);
      i--;
    }
    nxt[k][0] = mn;
  }
  nxt[X][0] = X;

  for (int t=1; t<20; t++)
    for (int k=0; k<=X; k++)
      nxt[k][t] = nxt[nxt[k][t-1]][t-1];

  // solve
  set<Interval> S = {{0, 0}, {X-1, X-1}}; // chosen intervals
  vector<int> ans;

  for (int i=0; i<N; i++) {
    auto it = S.lower_bound(I[i]);
    int s = I[i].s, e = I[i].e;
    int pe = prev(it)->e, ns = it->s;

    if (!(pe <= s && e <= ns)) continue; // overlap
    if (query(pe, s) + query(e, ns) + 1 != query(pe, ns)) continue; // not maximum

    S.insert(I[i]);
    ans.push_back(i);
  }

  cout << sz(ans) << endl;
  for (auto i: ans) cout << i+1 << ' ';

  ////////////////////////////////
  return 0;
}
