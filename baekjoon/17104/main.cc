#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;
using cpx = complex<double>;

////////////////////////////////////////////////////////////////
const double PI = acos(-1);
const int MAX_P = 1e6 + 5;
vector<cpx> primes(MAX_P, 1);
vector<cpx> goldbach;

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

void square() {
  int n = 1;
  while (n < primes.size()) n <<= 1;
  primes.resize(n); // already zero padded
  goldbach.resize(n);

  fft(primes, false);

  for (int i = 0; i < n; i++) {
    goldbach[i] = primes[i] * primes[i];
  }

  fft(goldbach, true);
}

void sieve() {
  primes[0] = primes[1] = 0;

  for (int i = 3; i < MAX_P; i += 2) {
    if (primes[i] != cpx(0, 0)) {
      for (int j = i * 3; j < MAX_P; j += i * 2) {
        primes[j] = 0;
      }
    }
  }
  for (int i = 0; i < MAX_P / 2; i++) primes[i] = primes[2 * i + 1];
  for (int i = MAX_P / 2; i < MAX_P; i++) primes[i] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  sieve();
  square();

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    if (N == 4) {
      cout << 1 << endl;
    } else {
      cout << ((int)round(goldbach[N/2 - 1].real()) + 1) / 2 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
