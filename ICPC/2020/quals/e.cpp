#include <bits/stdc++.h>

using namespace std;

int n, m;

struct dsu {
    vector<int> p, s;
    
    dsu(int sz) {
        p.resize(sz); s.resize(sz);
        for (int i=0; i<sz; i++) {
            p[i] = i;
            s[i] = 1;
        } 
    }

    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (s[x] < s[y]) swap(x, y);
        p[y] = x;
        s[x] += s[y];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    dsu D(n);

    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        if (D.find(a) == D.find(b)) {
            cout << i << endl;
            return 0;
        }
        D.merge(a, b);
    }
    
    cout << 0 << endl;
    return 0;
}