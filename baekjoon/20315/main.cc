#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MN = 300'001;

int N, M, K;
int par[MN], sz[MN];
int f[MN], inv[MN], g[MN];

struct Action { int t, a, b; };
Action A[MN];

struct Query { int i, s, m, t, a, b, pos; };
vector<Query> Q[MN];

int ans[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

int merge(int x, int y) {
  if (x == 0 || y == 0) return x+y; // 0: empty set
  x = find(x);
  y = find(y);
  if (x == y) return x;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> K >> N >> M;
  for (int i=1; i<=N-1; i++) {
    cin >> A[i].t >> A[i].a >> A[i].b;
  }
  for (int i=1; i<=M; i++) {
    Query q;
    q.i = i;
    cin >> q.s >> q.m >> q.t >> q.a >> q.b;
    Q[q.m].push_back(q);
  }
  for (int i=1; i<=K; i++) {
    sz[i] = 1;
    par[i] = f[i] = inv[i] = g[i] = i;
  }

  // scan forward
  for (int i=1; i<=N; i++) {
    for (auto &q: Q[i]) {
      q.pos = f[find(q.s)];
      if (q.t == 1) {
        if (q.pos == q.a || q.pos == q.b) q.pos = q.a+q.b-q.pos;
      } else {
        if (q.pos == q.a) q.pos = q.b;
      }
    }
    if (i == N) break;

    auto [t, a, b] = A[i];
    if (t == 1) {
      f[inv[a]] = b;
      f[inv[b]] = a;
      swap(inv[a], inv[b]);
    } else {
      if (inv[a] || inv[b]) {
        int r = merge(inv[a], inv[b]);
        f[r] = b;
        inv[a] = 0;
        inv[b] = r;
      }
    }
  }

  // scan backwards
  for (auto q: Q[N]) ans[q.i] = g[q.pos];
  for (int i=N-1; i>=1; i--) {
    auto [t, a, b] = A[i];
    if (t == 1) swap(g[a], g[b]);
    else g[a] = g[b];

    for (auto q: Q[i]) ans[q.i] = g[q.pos];
  }

  for (int i=1; i<=M; i++) cout << ans[i] << endl;

  return 0;
}
