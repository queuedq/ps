#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int MAXN = 1e5+5;
int n, k;
vector<int> adj[MAXN];
bool apart[MAXN], vst[MAXN];
int deg[MAXN];

void dfs(int u) {
    if (apart[u] || vst[u]) return;
    if (deg[u] != 1) return;
    vst[u] = true;
    for (auto v: adj[u]) {
        if (!vst[v]) {
            deg[v]--;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i=0; i<k; i++) {
        int a; cin >> a;
        apart[a] = true;
    }

    for (int i=1; i<=n; i++) {
        dfs(i);
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (!vst[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}