#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;

struct mint {
  lld x;

  mint() : x(0) {}
  mint(lld v) : x(v % MOD) {}

  mint operator+(mint rhs) { return mint(x + rhs.x); }
  mint operator*(mint rhs) { return mint(x * rhs.x); }
  mint& operator+=(mint rhs) { x = (x + rhs.x) % MOD; return *this; }
};

const int MN = 705;
int N;
vector<int> P;

mint D[MN][MN];     // "(...)"
mint D_mat[MN][MN]; // "[...]" | [...] means matched
mint E[MN][MN];     // "(..."X | rightmost color != X color | X comes as early as possible

inline int color(int i) { return abs(P[i]); }

int count(vector<int> P) {
  ::P = P;
  N = sz(P);

  for (int l=N-1; l>=0; l--) if (P[l] < 0) {
    for (int r=l+1; r<N; r++) {
      ////////////////////////
      // compute D

      if (P[r] > 0) {
        // match ends
        if (color(l) != color(r)) {
          // []
          D[l][r] = 1;
          for (int m=l+1; m<=r-1; m++) {
            if (P[m] == P[r]) { D[l][r] = 0; break; } // ) is not as early
          }

          // [ (... ]
          vector<bool> vst(N+1); // used colors for next (
          for (int m=l+1; m<=r-1; m++) {
            if (P[m] > 0 || vst[color(m)]) continue;
            vst[color(m)] = 1;
            if (color(l) != color(m)) D[l][r] += E[m][r-1];
          }

          D_mat[l][r] = D[l][r];
        }

        // split in two
        // (... + [...]
        for (int m=l+1; m<=r-1; m++) {
          D[l][r] += E[l][m-1] * D_mat[m][r];
        }
      }

      ////////////////////////
      // compute E

      if (r+1 < N) {
        for (int m=r; m>=l+1; m--) {
          if (P[m] == P[r+1]) break; // X is not as early
          if (color(m) != color(r+1)) E[l][r] += D[l][m];
        }
      }

    }
  }

  mint ans = 0;
  vector<bool> vst(N+1); // used colors for leftmost (
  for (int l=0; l<N; l++) {
    if (P[l] > 0 || vst[color(l)]) continue;
    vst[color(l)] = 1;
    for (int r=l+1; r<N; r++) ans += D[l][r];
  }

  return ans.x;
}
