#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dfs(int u, int gmax, int &cnt, vector<int> &num, vector<vector<int>> &links) {
    if (u == -1) return 0;

    int lg = dfs(links[u][0], gmax, cnt, num, links);
    int rg = dfs(links[u][1], gmax, cnt, num, links);
    if (lg > rg) swap(lg, rg); // lg is smaller

    if (lg + rg + num[u] <= gmax) return lg + rg + num[u];
    if (lg + num[u] <= gmax) { cnt += 1; return lg + num[u]; }
    cnt += 2; return num[u];
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int n = num.size();

    vector<int> indeg(n+1);
    for (auto link: links) {
        int l = link[0], r = link[1];
        if (l != -1) indeg[l]++;
        if (r != -1) indeg[r]++;
    }

    int mx = 0, root = 0;
    for (int i=0; i<n; i++) {
        if (indeg[i] == 0) root = i;
        mx = max(mx, num[i]);
    }

    int l = mx-1, r = 10'000 * 10'000;
    while (l+1 < r) {
        int m = (l+r)/2;
        int cnt = 0; // # of cuts
        dfs(root, m, cnt, num, links);
        if (cnt <= k-1) r = m;
        else l = m;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////

    // int k = 3;
    // vector<int> num = {12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1};
    // vector<vector<int>> links = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {8, 5}, {2, 10}, {3, 0}, {6, 1}, {11, -1}, {7, 4}, {-1, -1}, {-1, -1}};
    int k = 1;
    vector<int> num = {6, 9, 7, 5};
    vector<vector<int>> links = {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}};
    cout << solution(k, num, links) << endl;

    ////////////////////////////////
    return 0;
}
