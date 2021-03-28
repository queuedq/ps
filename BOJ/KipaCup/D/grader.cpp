#include <cstdio>
#include <algorithm>
#include <tuple>
#include <cassert>
#include "solution.h"

using namespace std;

int a[2019];

#define ensure(x, wan, fm) if (!(x)) { fprintf(stderr, "%s [%d]: %s\n", wan <= 0 ? "Data Error" : "Wrong Answer", ~wan, fm); return -1; }

int main() {
	int p, n;
	scanf("%d%d", &p, &n);
	ensure(30 <= p && p <= 50, 0, "p is not in range [30, 50]");
	ensure(n <= 1204, 0, "n is greater than 1204");
	int i, s = 0;
	int tk = 0, ntk = 0;
	bool last_pick = false;
	for (i=1; i<=n; ++i) {
		scanf("%d", a+i);
		ensure(a[i] == -100 || a[i] == 100 || a[i] == 200 || a[i] == 300 || a[i] == 600, ~i, "invalid present value");
		tie(tk, ntk) = pair<int, int>(ntk + a[i], max(tk, ntk));
	}
	tk = max(tk, ntk);

	init();
	last_pick = false;
	s = 0;
	for (i=1; i<=n; ++i) {
		bool this_pick = pick(a[i]);
		ensure (!(last_pick && this_pick), i, "consecutive fetch");
		if (this_pick) s += a[i];
		last_pick = this_pick;
	}
	fprintf(stderr, "Maximized Value: %d, Your Value = %d\n", tk, s);
	fprintf(stderr, "Ratio: %.2lf%%\n", (tk ? s / (double)tk : 1.) * 100);
	printf("%d\n", s * 100 >= tk * p);
	return 0;
}
