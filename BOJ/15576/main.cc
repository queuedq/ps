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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string A, B; cin >> A >> B;
  vector<cpx> a, b;
  for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
  for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');

  vector<cpx> c = multiply(a, b);
  vector<int> C(c.size() + 10);

  int carry = 0;
  for (int i = 0; i < C.size(); i++) {
    int num = carry;
    if (i < c.size()) num += round(c[i].real());
    C[i] = num % 10;
    carry = num / 10;
  }

  bool leadingZero = true;
  for (int i = C.size() - 1; i >= 0; i--) {
    if (leadingZero && C[i] == 0) continue;
    leadingZero = false;
    cout << C[i];
  }
  if (leadingZero) cout << 0;
  cout << endl;

  ////////////////////////////////
  return 0;
}
