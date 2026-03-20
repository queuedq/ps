#include <bits/stdc++.h>
#include "stations.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int id;
vector<int> adj[MN];

// zig-zag dfs order
void dfs(int u, int p, int d, vector<int> &A) {
	if (d%2 == 0) A[u] = id++;
	for (auto v: adj[u]) {
		if (v == p) continue;
		dfs(v, u, d+1, A);
	}
	if (d%2 == 1) A[u] = id++;
}

vector<int> label(int n, int k, vector<int> u, vector<int> v) {
	id = 0;
	for (int i=0; i<n; i++) adj[i].clear();

	for (int i=0; i<n-1; i++) {
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	vector<int> A(n);
	dfs(0, -1, 0, A);
	return A;
}

int find_next_station(int s, int t, vector<int> c) {
	if (c[0] < s) { // s is right child
		// parent
		if (t <= c[0] || t > s) return c[0];
		// child
		int i = upper_bound(all(c), t) - c.begin() - 1;
		return c[i];

	} else { // s is left child
		// parent
		if (t >= c.back() || t < s) return c.back();
		// child
		int i = lower_bound(all(c), t) - c.begin();
		return c[i];
	}
}
