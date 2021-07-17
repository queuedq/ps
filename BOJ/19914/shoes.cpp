#include "shoes.h"
#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int MN = 101010;
const int ST = 1<<18;
lld N, color[ST], L[ST], R[ST], seg[2][ST*2], abab, abba, swaps;
queue<pii> sizes[MN];

void upd(lld seg[], int i, int v) {
	seg[i+=ST] += v;
	for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int qry(lld seg[], int l, int r) {
	int ans = 0;
	for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
		if (l&1) ans += seg[l++];
		if (r&1) ans += seg[--r];
	}
	return ans;
}

long long count_swaps(std::vector<int> s) {
	N = s.size() / 2;

	// pair up shoes and count final swaps
	for (int i=0, c=1; i<N*2; i++) {
		queue<pii> &Q = sizes[abs(s[i])];
		if (Q.empty() || Q.front().first == s[i]) {
			Q.push({s[i], i});
		} else {
			if (s[i] < 0) swaps++;
			color[Q.front().second] = color[i] = c;
			L[c] = Q.front().second;
			R[c] = i;
			c++;
			Q.pop();
		}
	}

	// count abab / abba
	for (int i=0; i<N*2; i++) {
		int l = L[color[i]], r = R[color[i]];
		if (l == i) {
			upd(seg[0], i, 1);
		} else {
			upd(seg[0], l, -1);
			upd(seg[1], l, 1);
			abab += qry(seg[0], l+1, r-1);
			abba += qry(seg[1], l+1, r-1);
		}
	}

	return abab + abba*2 + swaps;
}
