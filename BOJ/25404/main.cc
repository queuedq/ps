#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using vec = vector<lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = LLONG_MAX;
lld N, M, A[MN];
vec xs, pos[MN], D[MN];

void erase(multiset<lld> &S, lld v) { S.erase(S.find(v)); }

// X, Y: prev/cur pos, D, E: prev/cur dp, all doubled
void dp(vec &X, vec &Y, vec &D, vec &E) {
  int n = sz(X)/2, m = sz(Y)/2;
  multiset<lld> S, T; // S: D+X, T: D-X, in (Y[s], Y[e])
  int l = 0, r = 0;
  
  // move in both directions
  for (int s=0, e=m-1; s<m; s++, e++) {
    while (r < n*2 && X[r] < Y[e]) S.insert(D[r]+X[r]), T.insert(D[r]-X[r]), r++;
    while (l < n*2 && X[l] < Y[s]) erase(S, D[l]+X[l]), erase(T, D[l]-X[l]), l++;

    if (sz(S)) E[e%m] = min(E[e%m], *S.begin() - Y[s] + (Y[e]-Y[s])); // s then e
    if (sz(T)) E[s%m] = min(E[s%m], *T.begin() + Y[e] + (Y[e]-Y[s])); // e then s
  }

  // move in one direction
  S.clear(), T.clear(), l = 0, r = 0;

  for (int s=0, e=1; s<m; s++, e++) {
    while (r < n*2 && X[r] < Y[e]) S.insert(D[r]+X[r]), T.insert(D[r]-X[r]), r++;
    while (l < n*2 && X[l] < Y[s]) erase(S, D[l]+X[l]), erase(T, D[l]-X[l]), l++;

    if (sz(S)) E[e%m] = min(E[e%m], *S.begin() - (Y[e]-N)); // left to e
    if (sz(T)) E[s%m] = min(E[s%m], *T.begin() + (Y[s]+N)); // right to s
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  xs.push_back(0); // start
  
  // compress
  sort(all(xs));
  M = unique(all(xs)) - xs.begin(); xs.resize(M);
  for (int i=0; i<N; i++) {
    A[i] = lower_bound(all(xs), A[i]) - xs.begin();
    pos[A[i]].push_back(i);
  }
  pos[0] = {0};

  // double the array
  for (int i=0; i<M; i++) {
    int n = sz(pos[i]);
    for (int j=0; j<n; j++) pos[i].push_back(pos[i][j]+N);
  }

  // DP
  D[0] = {0, 0};
  for (int i=1; i<M; i++) {
    int n = sz(pos[i])/2;
    D[i].resize(n*2, INF);
    dp(pos[i-1], pos[i], D[i-1], D[i]);
    for (int j=0; j<n; j++) D[i][j+n] = D[i][j]; // double
  }

  cout << *min_element(all(D[M-1])) << endl;

  ////////////////////////////////
  return 0;
}
