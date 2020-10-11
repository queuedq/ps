#include <bits/stdc++.h>

using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

void compress(vector<int> &xs) {
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
}

int idx(int x, const vector<int> &xs) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

struct segtree {
    vector<int> rmax;
    int size;

    segtree() {}
    
    void resize (int sz) {
        size = 1 << (int)ceil(log2(sz));
        rmax = vector<int>(size*2, INT_MIN);
    }

    void update(int i, int val) {
        rmax[size+i] = val;
        for (int n=(size+i)/2; n>0; n/=2) {
            rmax[n] = max(rmax[n*2], rmax[n*2+1]);
        }
    }

    int query(int l, int r) { return query(1, 0, size-1, l, r); }
    int query(int n, int nl, int nr, int l, int r) {
        if (nr < l || r < nl) return INT_MIN;
        if (l <= nl && nr <= r) return rmax[n];
        int mid = (nl+nr)/2;
        return max(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
    }
};

const int MAXN = 5e5+5;
int N, A[MAXN];
int D[MAXN][2][3]; // 0: inc, 1: dec / len 0, 1, 2+
vector<int> xs;
segtree seg[2][2]; // 0: inc, 1: dec / len 0, 1+

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        xs.push_back(A[i]);
    }
    compress(xs);

    seg[0][0].resize(N); seg[0][1].resize(N);
    seg[1][0].resize(N); seg[1][1].resize(N);

    // D[0][0][0] = 1; D[0][0][1] = INT_MIN; D[0][0][2] = INT_MIN;
    // D[0][1][0] = 1; D[0][1][1] = INT_MIN; D[0][1][2] = INT_MIN;

    seg[0][0].update(idx(A[0], xs), 1);
    seg[1][0].update(idx(A[0], xs), 1);

    for (int i=1; i<N; i++) {
        D[i][0][1] = seg[0][0].query(0, idx(A[i], xs)-1) + 1;
        D[i][0][2] = seg[0][1].query(0, idx(A[i], xs)-1) + 1;
        
        D[i][1][1] = seg[1][0].query(idx(A[i], xs)+1, N-1) + 1;
        D[i][1][2] = seg[1][1].query(idx(A[i], xs)+1, N-1) + 1;
        
        // D[i][0][0] = max(D[i][1][1], D[i][1][2]);
        // D[i][1][0] = max(D[i][0][1], D[i][0][2]);

        seg[0][0].update(idx(A[i], xs), D[i][1][2]);
        seg[0][1].update(idx(A[i], xs), max(D[i][0][1], D[i][0][2]));

        seg[1][0].update(idx(A[i], xs), D[i][0][2]);
        seg[1][1].update(idx(A[i], xs), max(D[i][1][1], D[i][1][2]));
    }

    // for (int i=0; i<N; i++) {
    //     cout << D[i][0][1] << " " << D[i][0][2] << " " << D[i][1][1] << " " << D[i][1][2] <<endl;
    // }

    int ans = 0;
    for (int i=0; i<N; i++) {
        ans = max({ans, D[i][0][2], D[i][1][2]});
    }

    cout << ans << endl;
    
    return 0;
}