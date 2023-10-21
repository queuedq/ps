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
int Q;
int X[MN], Y[MN], cnt[MN]; // cnt: number of blocks below it + itself
int L[MN][20], R[MN][20]; // next node sparse table
int top[MN*4]; // topmost block id

int furthest(int u, int h, int S[][20]) { // go furthest to S direction at height h
  for (int k=19; k>=0; k--)
    if (Y[S[u][k]] >= h) u = S[u][k];
  return u;
}

int common(int u, int v) {
  int l = -1, r = Y[u];
  while (l+1 < r) {
    int m = (l+r) / 2;
    int p = furthest(u, m, R), q = furthest(v, m, L);
    if (X[p] < X[q]) r = m;
    else l = m;
  }
  return furthest(u, l, R);
}

int count(vector<int> S) {
  int sum = 0;
  for (int u: S) sum += cnt[u];
  for (int i=0; i<sz(S)-1; i++) sum -= cnt[common(S[i], S[i+1])];
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> Q;
  for (int u=1; u<=Q; u++) {
    int t, x, y, w, h; cin >> t >> x;
    if (t == 1) w = 4, h = 1;
    else w = 1, h = 4;

    y = 0;
    for (int i=0; i<w; i++) y = max(y, Y[top[x+i]]);
    X[u] = x, Y[u] = y+h;

    // connect edges
    vector<int> S;
    for (int i=0; i<w; i++) {
      int v = top[x+i];
      if (Y[v] != y) continue;
      if (S.empty() || S.back() != v) S.push_back(v);
    }

    // get ans
    cnt[u] = count(S) + 1;
    cout << cnt[u] - 1 << endl;

    // update
    for (int i=0; i<w; i++) top[x+i] = u;

    L[u][0] = S.front(), R[u][0] = S.back();
    for (int k=1; k<20; k++) {
      L[u][k] = L[L[u][k-1]][k-1];
      R[u][k] = R[R[u][k-1]][k-1];
    }
  }

  ////////////////////////////////
  return 0;
}
