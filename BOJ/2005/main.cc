#include <bits/stdc++.h>
#include <cmath>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Bowl {
  double h, r, R, s; // s = h / (R-r)
};

double get_base(Bowl A, Bowl B) {
  if (A.R <= B.r) return A.h; // on top
  // don't consider A.r, just max with 0
  if (A.s <= B.s) // A touches bottom of B
    return max(A.h - (A.R-B.r) * A.s, 0.);
  if (B.R <= A.R) // A touches top of B
    return max(A.h - (A.R-B.R) * A.s - B.h, 0.);
  // B touches top of A
  return max(A.h - (A.R-B.r) * B.s, 0.);
}

const int MN = 10;
Bowl B[MN];
int N, vst[MN], stk[MN];
double base[MN], ans=INFINITY;

void calc() {
  double h = 0;
  for (int i=1; i<=N; i++) {
    int u = stk[i];
    base[u] = 0;
    for (int j=1; j<i; j++) {
      int v = stk[j];
      base[u] = max(base[u], base[v] + get_base(B[v], B[u]));
    }
    h = max(h, base[u] + B[u].h);
  }
  ans = min(ans, h);
}

void brute(int i) {
  if (i == N+1) return calc();

  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;
    vst[u] = 1, stk[i] = u;
    brute(i+1);
    vst[u] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    double h, r, R; cin >> h >> r >> R;
    B[i] = {h, r, R, h / (R-r)};
  }

  brute(1);
  cout << lld(ans) << endl;

  ////////////////////////////////
  return 0;
}
