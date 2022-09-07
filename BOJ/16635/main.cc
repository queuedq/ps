#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int N, K, A[MN][MN], vst[MN], S[MN], T[MN];
vector<int> adj[MN];

bool check() {
  // rows
  for (int i=1; i<=K; i++) {
    vector<int> used(N+1);
    for (int j=1; j<=N; j++) {
      if (used[A[i][j]]) return 0;
      used[A[i][j]] = 1;
    }
  }

  // columns
  for (int j=1; j<=N; j++) {
    vector<int> used(N+1);
    for (int i=1; i<=K; i++) {
      if (used[A[i][j]]) return 0;
      used[A[i][j]] = 1;
    }
  }

  return 1;
}

bool match(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;
  for (auto v: adj[u]) {
    if (!T[v] || match(T[v])) {
      S[u] = v;
      T[v] = u;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=K; i++) {
    for (int j=1; j<=N; j++) cin >> A[i][j];
  }

  // check possibility
  if (!check()) {
    cout << "no" << endl;
    return 0;
  }

  // build initial graph
  for (int u=1; u<=N; u++) {
    vector<int> used(N+1);
    for (int i=1; i<=N; i++) used[A[i][u]] = 1;
    for (int v=1; v<=N; v++) {
      if (!used[v]) adj[u].push_back(v);
    }
  }

  for (int i=K+1; i<=N; i++) {
    // match; always perfectly matched
    fill(S, S+N+1, 0);
    fill(T, T+N+1, 0);
    for (int u=1; u<=N; u++) {
      fill(vst, vst+N+1, 0);
      match(u);
    }

    // save
    for (int u=1; u<=N; u++) A[i][u] = S[u];

    // modify graph
    for (int u=1; u<=N; u++) {
      adj[u].erase(remove(all(adj[u]), S[u]), adj[u].end());
    }
  }

  cout << "yes" << endl;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) cout << A[i][j] << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
