#include <bits/stdc++.h>
#include "railroad.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////

vector<pii> encode_map(int N, int K, int &X, vector<pii> E) {
	vector<vector<int>> adj(N+1);
	for (auto e: E) {
		int u = e.first, v = e.second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> D(N+1);
	for (int i=1; i<=N; i++) {
		int mx = 0;
		
		vector<bool> vst(N+1);
		queue<int> Q;
		Q.push(i); vst[i] = 1; D[i] = 0;
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			mx = D[u];
			for (auto v: adj[u]) {
				if (!vst[v]) { Q.push(v); vst[v] = 1; D[v] = D[u]+1; }
			}
		}

		if (mx <= N/2) { X = i; break; }
	}

	vector<pii> ret;
	int cnt = 0;
	for (int i=1; i<=N; i++) {
		for (int j=i+1; j<=N; j++) {
			if (cnt < K && D[i] == D[j]) {
				ret.push_back({i, j});
				cnt++;
			}
		}
	}
	return ret;
}

vector<pii> decode_map(int N, int K, int X, vector<pii> E) {
	vector<vector<int>> adj(N+1);
	for (auto e: E) {
		int u = e.first, v = e.second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> D(N+1), vst(N+1);
	queue<int> Q;
	Q.push(X); vst[X] = 1; D[X] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (auto v: adj[u]) {
			if (!vst[v]) { Q.push(v); vst[v] = 1; D[v] = D[u]+1; }
		}
	}

	vector<pii> ret;
	for (auto e: E) {
		int u = e.first, v = e.second;
		if (D[u] != D[v]) ret.push_back({u, v});
	}
	return ret;
}
