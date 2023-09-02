#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld MOD;

struct mint {
  lld v;
  mint() = default;
  mint(int v): v(v) {}
  mint operator+(mint a) { return (v+a.v) % MOD; }
  mint operator-(mint a) { return (v-a.v+MOD) % MOD; }
  mint operator*(mint a) { return (v*a.v) % MOD; }
  mint operator+=(mint a) { return *this = *this + a; }
  mint operator-=(mint a) { return *this = *this - a; }
};

////////////////////////////////////////////////////////////////
// Permutation types
// - P(progression): 1 2 3 4, 4 3 2 1
// - F(interval-free): 2 4 1 3
// - tree structure: 2 (4 (6 5)) 1 3
// No same-way progression under P node
// Any permutation under F node

const int MN = 401;
int N;
mint fact[MN];
// P/F[n][k]: P/F node, n elements, k groups / S: sum P[n][2..n]
mint P[MN][MN], F[MN][MN], S[MN];
mint D[MN]; // interval-free perms

void dp(int n) {
  F[n][1] = fact[n];
  for (int k=2; k<=n; k++) {
    for (int m=1; m<=n; m++) { // last group size m
      P[n][k] += P[n-m][k-1] * P[m][1];
      F[n][k] += F[n-m][k-1] * fact[m];
    }
    S[n] += P[n][k];
  }
  P[n][1] = fact[n] - S[n];

  D[n] = fact[n] - S[n] * 2;
  for (int k=2; k<n; k++) D[n] -= F[n][k] * D[k];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T >> MOD;
  N = MN-1;

  fact[0] = 1;
  for (int i=1; i<=N; i++) fact[i] = fact[i-1] * i;

  // DP
  P[0][0] = F[0][0] = 1;
  for (int i=1; i<=N; i++) dp(i);
  D[2] = 2; // (1 2), (2 1) is both progression and interval-free

  // print
  while (T--) cin >> N, cout << D[N].v << endl;

  ////////////////////////////////
  return 0;
}
