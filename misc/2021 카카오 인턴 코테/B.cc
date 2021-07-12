#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

bool oob(int x, int y) {
    return x<0 || x>=5 || y<0 || y>=5;
}

bool fill_adj(vector<string> &mat, vector<vector<bool>> &adj, int x, int y) {
    for (int d=0; d<5; d++) {
        int xx = x+dx[d], yy = y+dy[d];
        if (oob(xx, yy) || mat[xx][yy] == 'X') continue;
        if (adj[xx][yy]) return false;
        adj[xx][yy] = true;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);

    for (int i=0; i<5; i++) {
        vector<vector<bool>> adj(5, vector<bool>(5, false));
        bool ok = true;

        for (int j=0; j<25; j++) {
            int x = j/5, y = j%5;
            if (places[i][x][y] == 'P') ok = fill_adj(places[i], adj, x, y);
            if (!ok) break;
        }
        answer[i] = ok;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////

    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };
    for (auto x: solution(places)) cout << x << endl;

    ////////////////////////////////
    return 0;
}
