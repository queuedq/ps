#include <string>
#include <vector>

using namespace std;

using lld = long long;
const lld INF = INT64_MAX;

vector<lld> solution(int n, int z, vector<vector<int>> roads, vector<lld> queries) {
    vector<vector<lld>> D(z*z);
    vector<lld> E(z*z); // min D[c][..]

    D[0].assign(n, 1);
    D[0][0] = 0;
    E[0] = 0;
    for (int c=1; c<z*z; c++) {
        D[c].assign(n, INF);
        E[c] = INF;
        for (auto r: roads) {
            int u = r[0], v = r[1], w = r[2];
            if (c < w) continue;
            if (D[c-w][u] == INF) continue;
            D[c][v] = min(D[c][v], D[c-w][u] + 1);

            E[c] = min(E[c], D[c][v]);
        }
        
        if (E[c] == INF) continue;
        for (int v=0; v<n; v++) D[c][v] = min(D[c][v], E[c] + 1);
    }

    // process queries
    for (auto e: E) printf("%d ", e);
    printf("\n");

    vector<lld> ans(queries.size());
    for (int i=0; i<queries.size(); i++) {
        lld q = queries[i];
        ans[i] = INF;
        for (int j=0; j<z; j++) {
            // assert(j*z + q%z + (q/z-j)*z == q);
            if (q/z-j >= 0 && E[j*z + q%z] != INF) {
                ans[i] = min(ans[i], E[j*z + q%z] + (q/z-j));
            }
        }
        if (ans[i] == INF) ans[i] = -1;
    }

    return ans;
}

int main() {
    int n = 5;
    int z = 5;
    vector<vector<int>> roads = {{1,2,3},{0,3,2}};
    vector<lld> queries = {0,1,2,3,4,5,6};
    // {0,-1,1,2,3,1,4}
    vector<lld> ans = solution(n, z, roads, queries);
    for (auto a: ans) printf("%d ", a);
}
