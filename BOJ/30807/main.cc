#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> par;

    void reset(int N) {
        par.resize(N + 1);
        for (int i = 1; i <= N; i++)
            par[i] = i;
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        par[y] = x;
        return true;
    }
};

struct Edge {
    int u, v;
    long long c;
    bool operator<(const Edge &E) const { return c < E.c; }
};

int N, M;
long long K;
vector<int> u, v;
vector<long long> l, r;
DisjointSet dsu;

long long mst(long long t) {
    // construct G_t
    vector<Edge> E;
    for (int i = 0; i < M; i++) {
        long long c = min(t, r[i] - l[i]);
        E.push_back({u[i], v[i], l[i] + c});
        t -= c;
    }
    sort(E.begin(), E.end());

    // find MST
    dsu.reset(N);
    long long sum = 0;
    for (auto [x, y, c] : E)
        if (dsu.merge(x, y))
            sum += c;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    u = v = vector<int>(M);
    l = r = vector<long long>(M);
    for (int i = 0; i < M; i++)
        cin >> u[i] >> v[i] >> l[i] >> r[i];

    long long X = 0;
    for (int i = 0; i < M; i++)
        X += r[i] - l[i];

    // binary search
    long long s = -1, e = X;
    while (s + 1 < e) {
        long long m = (s + e) / 2;
        if (mst(m) >= K)
            e = m;
        else
            s = m;
    }

    // print answer
    if (mst(e) == K) {
        cout << "YES\n";
        for (int i = 0; i < M; i++) {
            long long c = min(e, r[i] - l[i]);
            cout << l[i] + c << '\n';
            e -= c;
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
