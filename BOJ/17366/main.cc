#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, Q;
string S;
int par[MN], match[MN], len[MN], pos[MN];

struct Info { int l, r, dl, dr; };
Info anc[MN][20];

Info step(Info X, int k) {
  int l = X.l, r = X.r;
  int dl = min(X.dl + anc[l][k].dl, X.dr + anc[r][k].dl);
  int dr = min(X.dl + anc[l][k].dr, X.dr + anc[r][k].dr);
  return {anc[l][k].l, anc[l][k].r, dl, dr};
}

bool is_anc(int u, int v) {
  int l = par[u], r = match[l];
  int vl = par[v], vr = match[vl];
  return l == N || (l <= vl && vr <= r);
}

Info lift(int u, int v) {
  Info X = {u, u, 0, 0};
  for (int k=19; k>=0; k--) {
    if (!is_anc(anc[X.l][k].l, v)) X = step(X, k);
  }
  if (!is_anc(X.l, v)) X = step(X, 0);
  return X;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q >> S;

  // parse
  vector<int> stk = {N};
  par[N] = N, match[N] = N;
  for (int i=0; i<N; i++) {
    int p = stk.back();
    if (S[i] == '(') stk.push_back(i);
    if (S[i] == ')') match[p] = i, match[i] = p, p = par[p], stk.pop_back();

    int w = 1;
    if (S[i] == ')' && S[i-1] != '(') w = 2; // jump cost

    par[i] = p;
    pos[i] = (len[p] += w);
    if (S[i] == ')') ++len[match[i]];
  }

  // fill sparse array
  for (int i=0; i<N; i++) {
    int l = par[i], r = match[l], dl = pos[i], dr = len[l] - pos[i];
    if (l != N) dl = min(dl, dr+2), dr = min(dr, dl+2);
    anc[i][0] = {l, r, dl, dr};
  }

  for (int k=0; k<19; k++)
    for (int i=0; i<=N; i++)
      anc[i][k+1] = step(anc[i][k], k);

  // query
  for (int q=0; q<Q; q++) {
    int u, v; cin >> u >> v; u--, v--;

    Info pu = lift(u, v);
    Info pv = lift(v, u);
    int p = par[pu.l];
    assert(p == par[pv.l]);

    int d1 = abs(pos[pu.l] - pos[pv.r]);
    int d2 = abs(pos[pu.r] - pos[pv.l]);
    if (p != N) {
      d1 = min(d1, len[p]+2-d1);
      d2 = min(d2, len[p]+2-d2);
    }

    int d = min(pu.dl + d1 + pv.dr, pu.dr + d2 + pv.dl);
    cout << d << endl;
  }

  ////////////////////////////////
  return 0;
}
