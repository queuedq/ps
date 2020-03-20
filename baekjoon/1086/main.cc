#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 20;
const int MAXK = 105;
const int MAX2N = 1<<15;
string raw[MAXN];
int N, K, A[MAXN], B[MAXN];
lld D[MAX2N][MAXK];

lld gcd(lld a, lld b) {
  if (a < b) swap(a, b);
  while (b > 0) { lld r = a % b; a = b; b = r; }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N ;
  for (int i=0; i<N; i++) cin >> raw[i];
  cin >> K;

  for (int i=0; i<N; i++) {
    B[i] = 1;
    for (auto d: raw[i]) {
      A[i] = (A[i]*10+d-'0') % K;
      B[i] = B[i]*10 % K;
    }
  }

  D[0][0] = 1;
  for (int i=1; i<(1<<N); i++) {
    for (int j=0; j<N; j++) {
      int m = 1<<j;
      if (!(i & m)) continue;
      for (int k=0; k<K; k++) {
        D[i][(k*B[j]+A[j]) % K] += D[i^m][k];
      }
    }
  }

  lld cnt = D[(1<<N) - 1][0];
  lld fac = 1;
  for (int i=1; i<=N; i++) fac *= i;

  lld g = gcd(cnt, fac);
  cout << cnt/g << "/" << fac/g << endl;

  ////////////////////////////////
  return 0;
}
