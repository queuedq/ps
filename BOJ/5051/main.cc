#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

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

lld r(cpx z) {
  return round(z.real());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  vector<cpx> a(N);

  for (lld i = 1; i < N; i++) {
    a[i * i % N] += 1;
  }

  // for (int i = 0; i < a.size(); i++) cout << r(a[i]) << " "; cout << endl;

  vector<cpx> c = multiply(a, a);

  // for (int i = 0; i < c.size(); i++) cout << r(c[i]) << " "; cout << endl;

  lld ans = 0;
  for (int i = 0; i < c.size(); i++) {
    ans += r(c[i]) * r(a[i % N]);
  }
  for (int i = 0; i < a.size(); i++) { // a = b
    ans += r(a[i]) * r(a[i * 2 % N]);
  }

  cout << ans / 2 << endl;

  ////////////////////////////////
  return 0;
}
