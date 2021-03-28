#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

using cpx = complex<double>;
const double PI = acos(-1);

void fft(vector<cpx> &f, bool inv) {
    int n = f.size();

    for (int i=1, j=0; i<n; i++) {
        int bit = n>>1;
        for (; j>=bit; bit>>=1) j-= bit;
        j += bit;
        if (i < j) swap(f[i], f[j]);
    }

    for (int s=2; s<=n; s<<=1) {
        double t = 2*PI / s * (inv ? -1 : 1);
        cpx ws(cos(t), sin(t));
        for (int i=0; i<n; i+=s) {
            cpx w = 1;
            for (int j=0; j<s/2; j++) {
                cpx u = f[i+j], v = f[i+j + s/2] * w;
                f[i+j] = u + v;
                f[i+j + s/2] = u - v;
                w *= ws;
            }
        }
    }

    if (inv) {
        for (int i=0; i<n; i++) f[i] /= n;
    }
}

vector<lld> multiply(const vector<lld> &a, const vector<lld> &b) {
    vector<cpx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size()) * 2) n <<= 1;
    fa.resize(n); fb.resize(n);

    fft(fa, false); fft(fb, false);
    for (int i=0; i<n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<lld> res(n);
    for (int i=0; i<n; i++) res[i] = (lld)round(fa[i].real());
    return res;
}

const int MN = 30000;
const int MN2 = 60001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<lld> a(MN2), b(MN2), c(MN2*2);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        a[x+MN]++;
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        c[(x+MN)*2]++;
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        b[x+MN]++;
    }

    vector<lld> res = multiply(a,b);
    lld ans = 0;
    for (int i=0; i<MN2*2; i++) {
        if (c[i]) ans += res[i];
    }

    cout << ans << endl;

    return 0;
}