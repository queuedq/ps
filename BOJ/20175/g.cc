#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld n, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    lld mn = 1e17, mx = -1e17, mn2 = 1e17, mx2 = -1e17;
    for (int i=0; i<n; i++) {
        lld A; cin >> A;
        mn = min(mn, A - i*d);
        mx = max(mx, A - i*d);
        mn2 = min(mn2, A + i*d);
        mx2 = max(mx2, A + i*d);
    }

    lld ans = min(mx-mn, mx2-mn2);

    cout << ans / 2 << (ans % 2 ? ".5" : ".0") << endl;

    return 0;
}