#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Node {
    lld d; int u, m;
    bool operator <(const Node &N) const { return d > N.d; }
};

int trap_number(int u, vector<int> &traps) {
    for (int t=0; t<traps.size(); t++) {
        if (traps[t] == u) return t;
    }
    return -1;
}

bool is_active(int u, vector<int> &traps, int m) {
    int t = trap_number(u, traps);
    if (t == -1) return false;
    return (m>>t) & 1;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    vector<vector<pii>> adj(n+1);
    vector<vector<lld>> dst(n+1, vector<lld>(1024, -1));

    for (auto road: roads) {
        int P = road[0], Q = road[1], S = road[2];
        adj[P].push_back({Q, S});
        adj[Q].push_back({P, -S});
    }

    priority_queue<Node> pq;
    pq.push({0, start, 0});

    while (!pq.empty()) {
        auto [d, u, m] = pq.top(); pq.pop();
        if (dst[u][m] != -1) continue;
        dst[u][m] = d;
        if (u == end) return d;

        for (auto [v, w]: adj[u]) {
            if (is_active(u, traps, m) ^ is_active(v, traps, m)) w = -w;
            if (w < 0) continue;

            int t = trap_number(v, traps);
            if (t == -1) pq.push({d+w, v, m});
            else pq.push({d+w, v, m ^ (1<<t)});
        }
    }

    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////

    // int n = 3, start = 1, end = 3;
    // vector<vector<int>> roads = {{1, 2, 2}, {3, 2, 3}};
    // vector<int> traps = {2};
    int n = 4, start = 1, end = 4;
    vector<vector<int>> roads = {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
    vector<int> traps = {2, 3};
    cout << solution(n, start, end, roads, traps) << endl;

    ////////////////////////////////
    return 0;
}
