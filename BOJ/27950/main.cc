#include <bits/stdc++.h>
#include <climits>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
const lld INF = 1e18;
int N, s[MN]; // s[u]: # leaves in subtree u
vector<int> adj[MN];
vector<lld> D[MN], E[MN];

int gcnt(int tot, int g, int num) {
  // # leaves = tot, # small groups of size g = num
  // returns total group count
  return (tot - g*num) / 3 + num;
}

void dp(int u, int p) {
  s[u] = 0;
  D[u] = {0};
  E[u] = {0};

  for (auto v: adj[u]) {
    if (v == p) continue;
    dp(v, u);

    // temp D, E
    vector<lld> X(s[u]+s[v]+1, INF);
    vector<lld> Y(s[u]+s[v]+1, INF);

    // merge v into u
    for (int a=0; a<=s[u]; a++) {
      for (int b=0; b<=s[v]; b++) { // 1 + 1
        X[a+b] = min(X[a+b], D[u][a] + D[v][b]);
        if (a == 1 && b == 1) Y[1] = min(Y[1], D[u][a] + D[v][b]);
      }

      for (int b=0; b<=s[v]; b++) { // 1 + 2
        if (b <= a) X[a-b] = min(X[a-b], D[u][a] + E[v][b]);
        if (b >= a) Y[b-a] = min(Y[b-a], D[u][a] + E[v][b]);
      }
    }

    for (int a=0; a<=s[u]; a++) {
      for (int b=0; b<=s[v]; b++) { // 2 + 1
        if (b <= a) Y[a-b] = min(Y[a-b], E[u][a] + D[v][b]);
        if (b >= a) X[b-a] = min(X[b-a], E[u][a] + D[v][b]);
      }

      for (int b=0; b<=s[v]; b++) { // 2 + 2
        Y[a+b] = min(Y[a+b], E[u][a] + E[v][b]);
      }
    }

    // apply
    s[u] += s[v];
    D[u] = X;
    E[u] = Y;
  }

  if (u == 1) return;
  if (s[u] == 0) { // leaf
    s[u] = 1;
    D[u] = {INF, 0};
    E[u] = {INF, INF};
  }

  // update parent cost
  for (int i=0; i<=s[u]; i++) {
    D[u][i] += gcnt(s[u], 1, i);
    E[u][i] += gcnt(s[u], 2, i);
  }

  // for (int i=0; i<=s[u]; i++)
  //   if (D[u][i] < INF) printf("D[%d][%d] = %lld\n", u, i, D[u][i]);
  // for (int i=0; i<=s[u]; i++)
  //   if (E[u][i] < INF) printf("E[%d][%d] = %lld\n", u, i, E[u][i]);
  // printf("\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp(1, 0);

  lld ans = INF;
  for (int i=0; i<=s[1]; i++) ans = min({ans, D[1][i], E[1][i]});
  cout << ans * 2 << endl;

  ////////////////////////////////
  return 0;
}
