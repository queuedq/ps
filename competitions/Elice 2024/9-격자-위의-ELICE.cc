#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;

const lld INF = 1e12;
const int MN = 1010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int N, A[MN][MN];
pii elice[6];
lld D[6][MN][MN];

bool oob(int r, int c) { return r < 0 || r >= N || c < 0 || c >= N; }

void dijkstra(int i, lld D[MN][MN]) {
    using Info = pair<lld, pii>;
    priority_queue<Info, vector<Info>, greater<Info>> pq;
    
    for (int r=0; r<N; r++) for (int c=0; c<N; c++) D[r][c] = INF;
    D[elice[i].first][elice[i].second] = 0;
    pq.push({0, elice[i]});

    while (!pq.empty()) {
        auto [d, pos] = pq.top(); pq.pop();
        auto [r, c] = pos;
        if (D[r][c] != d) continue;
        for (int dir=0; dir<4; dir++) {
            int rr = r+dx[dir], cc = c+dy[dir];
            if (oob(rr, cc)) continue;
            lld dd = d + A[r][c] + A[rr][cc];
            if (dd < D[rr][cc]) pq.push({D[rr][cc] = dd, {rr, cc}});
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cin >> A[i][j];
    }
    for (int i=1; i<=5; i++) {
        int r, c; cin >> r >> c;
        elice[i] = {r-1, c-1};
    }

    for (int i=0; i<=5; i++) {
        dijkstra(i, D[i]);
    }
    
    lld cost1 = 0;
    for (int i=1; i<=5; i++) {
        cost1 += D[i-1][elice[i].first][elice[i].second];
    }

    swap(elice[1], elice[5]);
    swap(D[1], D[5]);
    lld cost2 = 0;
    for (int i=1; i<=5; i++) {
        cost2 += D[i-1][elice[i].first][elice[i].second];
    }

    cout << min(cost1, cost2) << endl;
    return 0;
}
