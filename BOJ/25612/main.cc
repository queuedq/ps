#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld MOD = 998'244'353;

lld modexp(lld a, lld e) {
  if (e == 0) return 1;
  lld r = modexp(a, e/2);
  r = r*r % MOD;
  if (e%2 == 0) return r;
  return r*a % MOD;
}

lld modinv(lld a) {
  return modexp(a, MOD-2);
}

////////////////////////////////////////////////////////////////
const int MN = 18;
int N, M, K;
vector<pii> swaps;
int arr[1<<MN], sorted[1<<MN];
lld D[MN+1][1<<MN]; // D[i][m]: placed numbers at m's set bits, i different numbers
lld S[MN+1][1<<MN]; // S[i][m]: subset sum of D[i][m]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<K; i++) {
    int x, y; cin >> x >> y;
    swaps.push_back({x-1, y-1});
  }

  // run swaps for all 0-1 partitions
  for (int m=0; m<1<<N; m++) arr[m] = m;
  for (auto [x, y]: swaps) {
    for (int m=0; m<1<<N; m++) {
      int a0 = arr[m]>>x & 1;
      int b0 = arr[m]>>y & 1;
      int a1 = a0 & b0; // min
      int b1 = a0 | b0; // max
      arr[m] ^= (a0^a1) << x;
      arr[m] ^= (b0^b1) << y;
    }
  }

  // check sorted
  for (int m=0; m<1<<N; m++) {
    sorted[m] = 1;
    for (int i=0; i<N-1; i++) {
      int a = arr[m]>>i & 1;
      int b = arr[m]>>(i+1) & 1;
      sorted[m] &= a <= b;
    }
  }

  // DP
  D[0][0] = 1;
  for (int m=0; m<1<<N; m++) S[0][m] = 1;

  for (int i=1; i<=N; i++) {
    for (int m=0; m<1<<N; m++) {
      if (!sorted[m]) continue;
      D[i][m] = (D[i][m] + S[i-1][m] - D[i-1][m] + MOD) % MOD;
    }

    // sum over subsets
    for (int m=0; m<1<<N; m++) S[i][m] = D[i][m];
    for (int j=0; j<N; j++) {
      for (int m=0; m<1<<N; m++) {
        if (m>>j & 1) S[i][m] = (S[i][m] + S[i][m^(1<<j)]) % MOD;
      }
    }
  }

  // get ans
  lld ans = 0;
  int mask = (1<<N) - 1;

  for (int i=1; i<=N; i++) {
    lld comb = 1; // choose i among M
    for (int j=1; j<=i; j++) {
      comb = comb * (M+1-j) % MOD;
      comb = comb * modinv(j) % MOD;
    }
    ans = (ans + D[i][mask] * comb) % MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
