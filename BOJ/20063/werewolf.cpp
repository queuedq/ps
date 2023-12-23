#include <bits/stdc++.h>
#include "werewolf.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
const int ST = 1<<18;

struct Tree {
  int N, t = 0;
  vector<int> adj[MN];
  int dsu[MN], par[MN][20], L[MN], R[MN];

  void reset(int N) {
    this->N = N;
    for (int u=0; u<N; u++) {
      dsu[u] = par[u][0] = u;
      L[u] = R[u] = -1;
    }
  }

  int find(int u) {
    if (u == dsu[u]) return u;
    return dsu[u] = find(dsu[u]);
  }

  void merge(int u, int v) {
    v = find(v);
    if (u == v) return;
    dsu[v] = par[v][0] = u;
    adj[u].push_back(v);
  }

  void sparse() {
    for (int k=1; k<20; k++)
      for (int u=0; u<N; u++)
        par[u][k] = par[par[u][k-1]][k-1];
  }

  int anc(int u, int lb, int ub) {
    for (int k=19; k>=0; k--) {
      int v = par[u][k];
      if (lb <= v && v <= ub) u = v;
    }
    return u;
  }

  void euler(int u) {
    L[u] = ++t;
    for (auto v: adj[u]) euler(v);
    R[u] = t;
  }
};

////////////////////////////////////////////////////////////////
struct Event { int i, l, r, sgn; };

vector<int> G[MN];
Tree t1, t2;
vector<Event> evt[MN];
int pos[MN], seg[ST*2], ans[MN];

void upd(int i, int v) {
  seg[i+=ST] += v;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int qry(int l, int r) {
  int sum = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) sum += seg[l++];
    if (r&1) sum += seg[--r];
  }
  return sum;
}

vector<int> check_validity(int N, vector<int> X, vector<int> Y,
                           vector<int> S, vector<int> E,
                           vector<int> L, vector<int> R) {
  int M = sz(X), Q = sz(S);
  for (int i=0; i<M; i++) {
    G[X[i]].push_back(Y[i]);
    G[Y[i]].push_back(X[i]);
  }

  // build dsu trees
  t1.reset(N), t2.reset(N); // human: S, [L, N-1] / wolf: E, [0, R]

  for (int u=N-1; u>=0; u--) { 
    for (auto v: G[u]) if (u < v) t1.merge(u, v);
  }
  for (int u=0; u<N; u++) {
    for (auto v: G[u]) if (v < u) t2.merge(u, v);
  }

  for (int u=0; u<N; u++) if (t1.dsu[u] == u) t1.euler(u);
  for (int u=0; u<N; u++) if (t2.dsu[u] == u) t2.euler(u);
  t1.sparse();
  t2.sparse();

  // make events
  for (int u=0; u<N; u++) pos[t1.L[u]] = t2.L[u];

  for (int i=0; i<Q; i++) {
    int u = t1.anc(S[i], L[i], N-1);
    int v = t2.anc(E[i], 0, R[i]);
    evt[t1.L[u]-1].push_back({i, t2.L[v], t2.R[v], -1});
    evt[t1.R[u]].push_back({i, t2.L[v], t2.R[v], 1});
  }

  // sweep
  for (int t=1; t<=N; t++) {
    upd(pos[t], 1);
    for (auto [i, l, r, sgn]: evt[t]) ans[i] += qry(l, r) * sgn;
  }

  // answer
  vector<int> ret(Q);
  for (int i=0; i<Q; i++) ret[i] = ans[i] > 0;
  return ret;
}
