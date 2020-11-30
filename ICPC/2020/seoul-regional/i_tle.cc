#pragma OPTIMIZE("O3")
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld INF = 1e15;

struct segtree {
    vector<vector<lld>> seg;
    int size;

    segtree(int sz) {
        size = 1 << (int)ceil(log2(sz));
        seg.resize(size*2);
        for (int i=0; i<size*2; i++) {
            seg[i].resize(size*2);
            fill(seg[i].begin(), seg[i].end(), -INF);
        }
    }

    void update(int i, int j, lld val) {
        for (int n = size+i; n > 0; n /= 2) {
            seg[n][size+j] = val;
            for (int m = (size+j)/2; m > 0; m /= 2) {
                seg[n][m] = max(seg[n][m*2], seg[n][m*2+1]);
            }
            
            if (n == size+i) continue;
            for (int m = size+j; m > 0; m /= 2) {
                seg[n][m] = max(seg[n*2][m], seg[n*2+1][m]);
            }
        }
    }

    lld q1(int n, int m, int md, int mu, int d, int u) {
        if (mu < d || u < md) return -INF;
        if (d <= md && mu <= u) return seg[n][m];
        int mid = (md+mu) / 2;
        return max(q1(n, m*2, md, mid, d, u), q1(n, m*2+1, mid+1, mu, d, u));
    }

    lld query(int l, int r, int d, int u) { return q2(1, 0, size-1, l, r, d, u); }
    lld q2(int n, int nl, int nr, int l, int r, int d, int u) {
        if (nr < l || r < nl) return -INF;
        if (l <= nl && nr <= r) return q1(n, 1, 0, size-1, d, u);
        int mid = (nl+nr) / 2;
        return max(q2(n*2, nl, mid, l, r, d, u), q2(n*2+1, mid+1, nr, l, r, d, u));
    }
};


const int MN = 2005;
const int MQ = 2e5+5;

lld n, m, A[MN];
lld S[MN][MN];

struct query {
    lld i, s, e, u;
    bool operator <(const query &q) const { return u < q.u; }
} Q[MQ];
lld ans[MQ];

struct cont {
    lld s, i, j;
    bool operator <(const cont &c) const { return s < c.s; }
};
vector<cont> ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<m; i++) {
        lld s, e, u; cin >> s >> e >> u;
        Q[i] = {i, s, e, u};
    }

    sort(Q, Q+m);

    for (int i=0; i<n; i++) {
        S[i][i] = A[i];
        ss.push_back({S[i][i], i, i});

        for (int j=i+1; j<n; j++) {
            S[i][j] = S[i][j-1] + A[j];
            ss.push_back({S[i][j], i, j});
        }
    }

    sort(ss.begin(), ss.end());

    segtree seg(n);
    int k = 0;
    for (int i=0; i<m; i++) {
        while (k < ss.size() && ss[k].s <= Q[i].u) {
            seg.update(ss[k].i, ss[k].j, ss[k].s);
            k++;
        }
        ans[Q[i].i] = seg.query(Q[i].s-1, Q[i].e-1, Q[i].s-1, Q[i].e-1);
    }

    for (int i=0; i<m; i++) {
        if (ans[i] == -INF) cout << "NONE" << endl;
        else cout << ans[i] << endl;
    }

    return 0;
}