#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_P = 50000;
bool P[MAX_P];
vector<lld> primes;

void getPrimes() {
  for (lld i = 2; i < MAX_P; i++) {
    P[i] = true;
  }

  for (lld i = 2; i < MAX_P; i++) {
    if (P[i]) {
      for (lld j = i * 2; j < MAX_P; j += i) {
        P[j] = false;
      }
    }
  }

  for (lld i = 2; i < MAX_P; i++) {
    if (P[i]) primes.push_back(i);
  }
}

lld phi(lld n) {
  lld res = n;
  for (lld p: primes) {
    if (p > n) break;
    if (n % p == 0) res -= res / p;
    while (n % p == 0) n /= p;
  }
  if (n > 1) res -= res / n;
  return res;
}

lld pow(lld n, lld e, lld m) {
  lld b = 0, res = 1;
  while ((1LL << b) <= e) b++;
  while (b--) {
    res = res * res % m;
    if ((1LL << b) & e) {
      res = res * n % m;
    }
  }
  return res;
}

lld tetration(lld n, lld m) {
  if (m == 1) return 0;
  lld e = phi(m) + tetration(n, phi(m));
  return pow(n, e, m);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  getPrimes();
  lld T; cin >> T;
  for (lld i = 0; i < T; i++) {
    lld N, M; cin >> N >> M;
    cout << tetration(N, M) << endl;
  }

  ////////////////////////////////
  return 0;
}
