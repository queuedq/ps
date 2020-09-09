#include "template.h"

using cpx = complex<double>;
const double PI = acos(-1);

// source: https://blog.myungwoo.kr/54
// re-written by me (queued_q)
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
        cpx u = f[i+j], v = f[i+j + s/2] * w; // u: f_even, v: f_odd
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
  a.resize(n); b.resize(n);
  fft(a, false); fft(b, false);

  vector<cpx> c(n);
  for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
  fft(c, true);
  return c;
}

int cpxToInt(cpx z) { return (int)round(z.real()); }
