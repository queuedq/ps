#include "gap.h"
#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

const lld MX = 1e18;

pll query(lld a, lld b) {
	lld mn, mx;
	MinMax(a, b, &mn, &mx);
	return {mn, mx};
}

lld solve1(int N) {
	lld s = -1, e = MX+1;
	lld best = 0;
	for (int i=N; i>0; i-=2) {
		auto [p, q] = query(s+1, e-1);
		if (s != -1) best = max({best, p-s, e-q});
		s = p, e = q;
	}
	best = max(best, e-s);
	return best;
}

lld solve2(int N) {
	// split [l+1, r-1] (N-2 points) into N-1 intervals
	// pigeonhole principle -> at least one interval is clear -> contained in max gap
	auto [l, r] = query(0, MX);
	lld d = (r-l-1) / (N-1), k = (r-l-1) % (N-1);

	lld last = l, best = 0;
	for (lld i=0, s=l+1; i<N-1; i++) {
		lld e = s + d + (i<k);
		auto [p, q] = query(s, e-1);
		if (p != -1) {
			best = max(best, p-last);
			last = q;
		}
		s = e;
	}

	best = max(best, r - last);
	return best;
}

lld findGap(int T, int N) {
	if (T == 1) return solve1(N);
	return solve2(N);
}
