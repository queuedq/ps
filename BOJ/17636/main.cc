#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, Q, A[MN];
pll bit[MN], ans[MN];

pll operator +(pll X, pll Y) { return {X.first + Y.first, X.second + Y.second}; }

struct Query { int typ, a, b, t; };
vector<Query> qry;

struct Interval {
  int l, r, t, w; // interval [l, r], weight w * (x-t)
  bool operator <(const Interval &I) const { return r < I.r; }
};
set<Interval> I;
vector<Interval> history[MN];

void toggle(int x, int t) {
  auto it = I.lower_bound({0, x, 0, 0});
  if (it->l <= x) { // 1 -> 0
    int l = it->l, r = it->r;
    history[t].push_back({l, r, t, -1});
    I.erase(it);

    if (l < x) {
      I.insert({l, x-1, t, 1});
      history[t].push_back({l, x-1, t, 1});
    }
    if (x < r) {
      I.insert({x+1, r, t, 1});
      history[t].push_back({x+1, r, t, 1});
    }
  } else { // 0 -> 1
    auto pt = prev(it);
    int l = x, r = x;
    if (x+1 == it->l) { // right
      r = it->r;
      history[t].push_back({x+1, r, t, -1});
      I.erase(it);
    }
    if (x-1 == pt->r) { // left
      l = pt->l;
      history[t].push_back({l, x-1, t, -1});
      I.erase(pt);
    }

    I.insert({l, r, t, 1});
    history[t].push_back({l, r, t, 1});
  }
}

void add(int i, pll v) {
  for (; i<MN; i+=i&-i) bit[i] = bit[i] + v;
}

pll sum(int i) {
  pll res = {0, 0};
  for (; i>0; i-=i&-i) res = res + bit[i];
  return res;
}

void dnc(int s, int e) { // solve for time [s, e]
  if (s == e) return;
  int m = (s+e)/2;

  // apply history[s..m]
  vector<array<int, 4>> E; // x, y, pair to add
  for (int t=s; t<=m; t++) {
    for (auto [l, r, _, w]: history[t]) {
      E.push_back({l, l, -t*w, w});
      E.push_back({l, r+1, t*w, -w});
      E.push_back({r+1, l, t*w, -w});
      E.push_back({r+1, r+1, -t*w, w});
    }
  }
  sort(all(E), [](auto X, auto Y) { return X[0] < Y[0]; });

  // add for qry[m+1..e] of type "query"
  vector<Query> sub_qry;
  for (int t=m+1; t<=e; t++) {
    if (qry[t].typ == 1) sub_qry.push_back(qry[t]);
  }
  sort(all(sub_qry), [](auto X, auto Y) { return X.a < Y.a; });

  int i = 0;
  for (auto [x, y, tw, w]: E) {
    while (i < sz(sub_qry) && sub_qry[i].a < x) {
      auto [typ, a, b, t] = sub_qry[i];
      ans[t] = ans[t] + sum(b);
      i++;
    }
    add(y, {tw, w});
  }

  // dnc
  dnc(s, m);
  dnc(m+1, e);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // input
  cin >> N >> Q;
  for (int i=1; i<=N; i++) {
    char c; cin >> c;
    A[i] = c-'0';
  }

  qry.push_back({-1, 0, 0, 0});
  for (int t=1; t<=Q; t++) {
    string typ; cin >> typ;
    if (typ == "toggle") {
      int i; cin >> i;
      qry.push_back({0, i, 0, t});
    } else {
      int a, b; cin >> a >> b; b--;
      qry.push_back({1, a, b, t});
    }
  }

  // get history
  for (int i=1, l=0; i<=N+1; i++) {
    if (!A[i-1] && A[i]) l = i;
    if (A[i-1] && !A[i]) {
      I.insert({l, i-1, 0, 1});
      history[0].push_back({l, i-1, 0, 1});
    }
  }
  I.insert({-1, -1, 0, 0});
  I.insert({N+2, N+2, 0, 0});

  for (int t=1; t<=Q; t++) {
    auto [typ, a, b, _] = qry[t];
    if (typ == 0) toggle(a, t);
  }

  I.clear();

  // dnc
  dnc(0, Q);

  for (int t=1; t<=Q; t++) {
    if (qry[t].typ == 1)
      cout << (ans[t].first + ans[t].second * t) << endl;
  }
  // for (int t=1; t<=Q; t++) {
  //   cout << t;
  //   if (qry[t].typ == 0) cout << endl;
  //   else cout << " " << ans[t].first << " " << ans[t].second << endl;
  // }

  ////////////////////////////////
  return 0;
}
