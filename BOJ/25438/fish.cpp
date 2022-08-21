#include "fish.h"

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;

struct Fish {
  lld x, y, w;
  bool operator <(const Fish &F) const { return y < F.y; }
};
vector<Fish> A[MN];
vector<lld> S[MN], P[MN], Q[MN], R[MN];
// S: psum of W[i]
// P: pmax of D[i] - S[i]
// Q: pmax of E[i]
// R: smax of E[i] + S[i+1]
vector<lld> D[MN], E[MN];
// D: h[i-1] < h[i]
// E: any

lld max_weights(int N, int M, vector<int> X, vector<int> Y, vector<int> W) {
  for (int i=0; i<M; i++) A[X[i]].push_back({X[i], Y[i], W[i]});
  for (int i=0; i<=N; i++) {
    sort(all(A[i]));
    A[i].push_back({i, N, 0});

    S[i].resize(sz(A[i])); // w prefix sum
    for (int j=1; j<sz(A[i]); j++) S[i][j] = S[i][j-1] + A[i][j-1].w;
  }

  for (int i=0; i<N; i++) {
    int n = sz(A[i]);
    D[i].resize(n); E[i].resize(n);

    for (int j=0; j<n; j++) {
      int k=0, l=0;
      if (i >= 1) k = lower_bound(all(A[i-1]), A[i][j]) - A[i-1].begin();
      if (i >= 2) l = lower_bound(all(A[i-2]), A[i][j]) - A[i-2].begin();
      
      if (i >= 1) D[i][j] = max(D[i][j], P[i-1][k] + S[i-1][k]);
      if (i >= 2) D[i][j] = max(D[i][j], Q[i-2][l] + S[i-1][k]);
      if (i >= 2) D[i][j] = max(D[i][j], R[i-2][l]);

      if (i >= 1) E[i][j] = max(D[i][j], R[i-1][k] - S[i][j]);
    }

    // calc useful values
    P[i].resize(n); Q[i].resize(n); R[i].resize(n);

    for (int j=1; j<n; j++) {
      P[i][j] = max(P[i][j-1], D[i][j-1] - S[i][j-1]);
      Q[i][j] = max(Q[i][j-1], E[i][j-1]);
    }
    R[i][n-1] = E[i][n-1] + S[i+1].back();
    for (int j=n-2; j>=0; j--) {
      int k = lower_bound(all(A[i+1]), A[i][j]) - A[i+1].begin();
      R[i][j] = max(R[i][j+1], E[i][j] + S[i+1][k]);
    }
  }

  return *max_element(all(E[N-1]));
}
