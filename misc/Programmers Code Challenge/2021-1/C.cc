#include <string>
#include <vector>

using namespace std;

long long dfs(int u, int p, vector<vector<int>> &adj, vector<long long> &a) {
    long long ans = 0;
    for (auto v: adj[u]) {
        if (v == p) continue;
        ans += dfs(v, u, adj, a);
    }
    if (p != -1) {
        a[p] += a[u];
        ans += abs(a[u]); 
    }
    return ans;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    int V = a.size(), E = edges.size();
    vector<long long> b(V);

    long long sum = 0;
    for (int i=0; i<V; i++) {
        b[i] = a[i];
        sum += b[i];
    }
    if (sum != 0) return -1;

    vector<vector<int>> adj(V);
    for (int i=0; i<E; i++) {
        int a = edges[i][0], b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return dfs(0, -1, adj, b);
}

int main() {
    vector<int> a = {-5,0,2,1,2};
    vector<vector<int>> edges = {{0,1}, {3,4}, {2,3}, {0,3}};
    printf("%d", solution(a, edges));
}
