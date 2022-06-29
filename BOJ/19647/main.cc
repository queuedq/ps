#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, vst[MN], S[MN], T[MN];
vector<int> adj[MN];

bool match(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;
  for (auto v: adj[u]) {
    if (!T[v] || match(T[v])) { S[u] = v, T[v] = u; return 1; }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) {
    int a; cin >> a;
    for (int i=0; i<a; i++) {
      int v; cin >> v;
      adj[u].push_back(v);
    }
  }

  for (int u=1; u<=N; u++) {
    fill(vst, vst+N+1, 0);
    match(u);
  }

  for (int u=1; u<=N; u++) { // remove u-v edge and match
    T[S[u]] = 0;

    fill(vst, vst+N+1, 0);
    vst[u] = 1;
    for (auto v: adj[u]) {
      if (v != S[u] && match(T[v])) { cout << -1 << endl; return 0; }
    }

    T[S[u]] = u;
  }

  cout << 1 << endl;
  for (int u=1; u<=N; u++) cout << S[u] << ' ';

  ////////////////////////////////
  return 0;
}
