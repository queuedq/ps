#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Line {
	mutable lld k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(lld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const lld inf = LLONG_MAX;
	lld div(lld a, lld b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(lld k, lld m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	lld query(lld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, x[MN], p[MN], s[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<N; i++) {
    int d; cin >> d;
    x[i] = x[i-1] + d;
  }
  for (int i=0; i<N-1; i++) cin >> p[i] >> s[i];

  D[0] = 0;
  LineContainer L;
  L.add(-s[0], -p[0]);
  for (int i=1; i<N; i++) {
    D[i] = -L.query(x[i]);
    L.add(-s[i], -(D[i] + p[i] - s[i]*x[i]));
  }

  cout << D[N-1] << endl;

  ////////////////////////////////
  return 0;
}
