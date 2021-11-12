#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, M, S[MAXN], tmp[MAXN];
vector<lld> xs;

struct Query { lld q, i, x, l, r, t; };
vector<Query> qry;

struct fenwick_tree {
  vector<lld> F;
  fenwick_tree(int sz) { F.resize(sz+1); }

  void add(int i, lld x) {
    for (; i<F.size(); i += i&-i) F[i] += x;
  }

  lld sum(int i) { // [1, i]
    lld s = 0;
    for (; i>0; i -= i&-i) s += F[i];
    return s;
  }
};

int compress(lld x) { // to 1-based
  return lower_bound(all(xs), x) - xs.begin() + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> S[i];
    tmp[i] = S[i];
    xs.push_back(S[i]);
  }

  for (int j=0; j<M; j++) {
    lld q, i, x, l, r, t; cin >> q;
    if (q <= 2) {
      cin >> i >> x;
      if (q == 2) x = -x;
      qry.push_back({q, i, x, 0, 0, 0});
      tmp[i] += x;
      xs.push_back(tmp[i]);
    }
    if (q == 3) { cin >> l >> r; qry.push_back({q, 0, 0, l, r, 0}); }
    if (q == 4) { cin >> t; qry.push_back({q, 0, 0, 0, 0, t}); }
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  fenwick_tree F(xs.size());
  for (int i=1; i<=N; i++) F.add(compress(S[i]), 1);

  // for (int i=0; i<xs.size(); i++) cout << xs[i] << ", "; cout << endl;

  for (int j=0; j<M; j++) {
    Query Q = qry[j];

    // for (int i=0; i<xs.size(); i++) cout << F.sum(i+1) << " "; cout << endl;
    // cout << "qry " << j << endl;

    if (Q.q <= 2) {
      F.add(compress(S[Q.i]), -1);
      S[Q.i] += Q.x;
      F.add(compress(S[Q.i]), 1);
    }

    if (Q.q == 3) {
      int li = compress(Q.l);
      int ri = compress(Q.r+1)-1;
      cout << F.sum(ri) - F.sum(li-1) << endl;
    }

    if (Q.q == 4) {
      lld l = 0, r = xs.size();
      while (l+1 < r) {
        lld m = (l+r) / 2;
        if (F.sum(m) >= Q.t) r = m;
        else l = m;
      }
      cout << xs[r-1] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
