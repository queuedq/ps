#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld MAX_P = 1e5;
bool isPrime[MAX_P];
vector<lld> primes;

void getPrimes() {
  fill(isPrime, isPrime + MAX_P, true);
  isPrime[0] = isPrime[1] = false;
  for (lld i = 2; i < MAX_P; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (lld j = i * 2; j < MAX_P; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

lld phi(lld n) {
  lld res = n;
  for (lld p: primes) {
    if (n % p == 0) res = res / p * (p-1);
    while (n % p == 0) n /= p;
  }
  if (n == 1) return res;
  return res / n * (n-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////
  getPrimes();

  while (true) {
    lld n; cin >> n;
    if (n == 0) break;

    if (n == 1) {
      cout << 0 << endl;
      continue;
    }

    cout << phi(n) << endl;
  }

  ////////////////////////////////
  return 0;
}
