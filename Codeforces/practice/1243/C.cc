#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define P_MAX 1000005
lld n;
bool isPrime[P_MAX];
vector<int> primes;

void sieve() {
  for (int i = 0; i < P_MAX; i++) {
    isPrime[i] = true;
  }
  for (int d = 2; d < P_MAX; d++) {
    if (isPrime[d]) {
      primes.push_back(d);
      for (int k = d * 2; k < P_MAX; k += d) {
        isPrime[k] = false;
      }
    }
  }
}

lld testPower(lld n) {
  int p = 0;
  for (int q: primes) {
    if (n % q == 0) {
      p = q;
      break;
    }
  }
  if (p == 0) {
    return n;
  }
  while (n % p == 0) {
    n = n / p;
  }
  if (n == 1) {
    return p;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  sieve();
  cin >> n;
  cout << testPower(n) << endl;

  ////////////////////////////////
  return 0;
}
