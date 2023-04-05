#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using pii = pair<int, int>;

const int MAXN = 20005;
int N, M;
bool vst[MAXN], color[MAXN];
vector<pii> adj[MAXN];
vector<int> ans;

void dfs(int u, bool c, vector<int> &path) {
    if (!ans.empty()) return;
    if (vst[u]) return;
    vst[u] = true;
    color[u] = c;
    for (auto [v, w]: adj[u]) {
        if (ans.empty() && vst[v] && c^w != color[v]) {
            for (int i=path.size()-1; i>=0; i--) {
                if (path[i] == v) break;
                ans.push_back(path[i]);
            }
            ans.push_back(v);
        }
        path.push_back(v);
        dfs(v, c^w, path);
        path.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c==-1});
        adj[b].push_back({a, c==-1});
    }

    vector<int> path;
    for (int i=1; i<=N; i++) {
        if (!ans.empty()) break;
        if (vst[i]) continue;
        dfs(i, 0, path);
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        cout << 1 << endl;
        cout << ans.size() << endl;
        for (auto a: ans) cout << a << endl;
    }

    return 0;
}