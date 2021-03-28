#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
using cpx = complex<double>;
const double PI = acos(-1);

void fft(vector<cpx> &f, bool inv){
  int n = f.size(), j = 0; // j: bit reverse of i

  for (int i = 1; i < n; i++) { // permute to separate f_even and f_odd
    int bit = (n >> 1);
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(f[i], f[j]);
  }

  for (int s = 2; s <= n; s <<= 1) { // length of each interval
    double t = 2*PI / s * (inv ? -1 : 1);
    cpx ws(cos(t), sin(t)); // w ** s == 1
    for (int i = 0; i < n; i += s) { // start of each interval
      cpx w = 1;
      for (int j = 0; j < s/2; j++) { // merge
        // u: f_even, v: f_odd
        cpx u = f[i+j], v = f[i+j + s/2] * w;
        f[i+j] = u + v;
        f[i+j + s/2] = u - v;
        w *= ws;
      }
    }
  }

  if (inv) {
    for (int i = 0; i < n; i++) f[i] /= n;
  }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b) {
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  a.resize(n);
  b.resize(n);

  fft(a, false);
  fft(b, false);

  vector<cpx> c(n);
  for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

  fft(c, true);

  return c;
}

int cpxToInt(cpx z) { return (int)round(z.real()); }

////////////////////////////////
int N;
vector<cpx> x, y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  x.resize(N); y.resize(N);
  for (int i = 0; i < N; i++) { cin >> x[i]; }
  for (int i = 0; i < N; i++) { cin >> y[i]; }

  reverse(y.begin(), y.end());
  for (int i = 0; i < N; i++) { y.push_back(y[i]); }

  vector<cpx> z = multiply(x, y);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, cpxToInt(z[i+N]));
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
