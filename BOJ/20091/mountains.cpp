#include "mountains.h"
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point {
  lld x, y;
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
};
lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }

const int MN = 2005;
int D[MN][MN];

int maximum_deevs(vector<int> y) {
	int N = y.size();

	D[0][0] = 1;
	for (int r=1; r<N; r++) {
		D[r][r] = 1;
		int i = r; // last visible

		// include r
		for (int l=r-1; l>=0; l--) {
			if (ccw({l, y[l]}, {i, y[i]}, {r, y[r]}) >= 0) { // visible
				D[l][r] = D[l+1][r];
				i = l;
			} else {
				D[l][r] = D[l+1][r] - D[l+1][i-1] + D[l][i-1];
			}
		}

		// max in [l, r]
		for (int l=r; l>=0; l--) {
			D[l][r] = max(D[l][r], D[l][r-1]);
		}
	}

	return D[0][N-1];
}
