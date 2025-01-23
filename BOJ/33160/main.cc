#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 405;
const int INF = 1e9 + 5;
int N, A[MN], F[3][3][3][5];
vector<int> adj[MN];

struct Interval {
  int s, e, a, b; // [s, e], odd index: a, even index: b
  int get(int x) { return (x%2 ? a : b); }
};
deque<Interval> D[MN];

Interval inter(Interval X, Interval Y) {
  return {max(X.s, Y.s), min(X.e, Y.e), X.a^Y.a, X.b^Y.b};
}

deque<Interval> merge(deque<Interval> &X, deque<Interval> &Y) { // xor
  deque<Interval> Z;
  int i = 0, j = 0;
  while (i < sz(X) && j < sz(Y)) {
    Interval I = inter(X[i], Y[j]);
    Z.push_back(I);
    if (I.e == X[i].e) i++;
    if (I.e == Y[j].e) j++;
  }
  return Z;
}

int mex(int a, int b) {
  if (a != 0 && b != 0) return 0;
  if (a != 1 && b != 1) return 1;
  return 2;
}

void dp(int u) {
  deque<Interval> X = {{0, INF, 0, 0}};
  for (auto v: adj[u]) {
    dp(v);
    X = merge(X, D[v]);
  }

  // adjust zero padding
  X.back().e = A[u]-1;
  if (X.back().s > X.back().e) X.pop_back();

  // dp
  D[u] = {{A[u], INF, 0, 0}};
  int g = 0; // last grundy number

  for (int i=sz(X)-1; i>=0; i--) {
    auto [s, e, a, b] = X[i];
    a = min(a, 2), b = min(b, 2); // 3 doesn't affect mex
    bool sw = e%2 == 0;

    auto f = F[a][b][g];
    if (sw) f = F[b][a][g];

    int f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    if (sw) swap(f1, f2), swap(f3, f4);

    // push new intervals
    D[u].push_front({max(s, e-1), e, f1, f2});
    if (s <= e-2) D[u].push_front({s, e-2, f3, f4});

    // update g
    g = D[u].front().get(s);
  }
}

void solve() {
  cin >> N;
  for (int i=2, p; i<=N; i++) { cin >> p; adj[p].push_back(i); }
  for (int i=1; i<=N; i++) cin >> A[i];

  // dp
  dp(1);
  cout << (D[1][0].b > 0 ? "First" : "Second") << endl;

  // reset
  for (int i=1; i<=N; i++) adj[i].clear(), D[i].clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // precompute dp table
  // has period 2, excluding first 2 values
  for (int a=0; a<3; a++) {
    for (int b=0; b<3; b++) {
      for (int c=0; c<3; c++) { // initial value
        F[a][b][c][0] = c;
        for (int i=1; i<=4; i++) F[a][b][c][i] = mex(F[a][b][c][i-1], (i%2) ? a : b);
        // debug
        // cout << "x "; for (int i=1; i<=4; i++) cout << (i%2 ? a : b) << " "; cout << endl;
        // for (int i=0; i<=4; i++) cout << F[a][b][c][i] << " "; cout << endl; cout << endl;
      }
    }
  }

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
