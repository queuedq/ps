#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MN = 300'001;

int N, M, K;
int f[MN], inv[MN], g[MN];

struct Action { int t, a, b; };
Action A[MN];

struct Query { int i, s, m, t, a, b, pos; };
vector<Query> Q[MN];

int ans[MN];

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
  for (int i=1; i<=K; i++) f[i] = inv[i] = g[i] = i;

  // scan forward
  for (int i=1; i<=N; i++) {
    for (auto &q: Q[i]) {
      q.pos = f[q.s];
      if (q.t == 1) {
        if (q.pos == q.a || q.pos == q.b) q.pos = q.a+q.b-q.pos;
      } else {
        if (q.pos == q.a) q.pos = q.b;
      }
    }
    if (i == N) break;

    auto [t, a, b] = A[i];
    f[inv[a]] = b;
    f[inv[b]] = a;
    swap(inv[a], inv[b]);
  }

  // scan backwards
  for (auto q: Q[N]) ans[q.i] = g[q.pos];
  for (int i=N-1; i>=1; i--) {
    auto [t, a, b] = A[i];
    swap(g[a], g[b]);

    for (auto q: Q[i]) ans[q.i] = g[q.pos];
  }

  for (int i=1; i<=M; i++) cout << ans[i] << endl;

  return 0;
}
