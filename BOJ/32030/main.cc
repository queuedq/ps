#include <bits/stdc++.h>
#include <queue>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int ML = 505050;
int N, L, bug[26][26], z[ML];
string S, C, T;
vector<pll> adj[ML];
lld D[ML];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S >> C >> T;
  L = sz(T);
  for (int i=0; i<N; i++) bug[S[i]-'a'][C[i]-'a'] = 1;

  // z
  int l = 0, r = 0;
  for (int i=1; i<L; i++) {
    if (i < r) z[i] = min(z[i-l], r-i);
    while (i+z[i] < L && T[z[i]] == T[i+z[i]]) z[i]++;
    if (z[i] > r) l = i, r = i+z[i];
  }

  // build graph
  adj[0].push_back({1, 1});
  for (int i=1; i<L; i++) {
    int j = i + min(z[i], i); // matching index after doubling
    if (j == i*2 && bug[T[i-1]-'a'][T[j]-'a']) j++; // take advantage of buggy char

    bool b1 = !bug[T[i-1]-'a'][T[i]-'a'];
    bool b2 = 0;
    for (int c=0; c<26; c++) b2 |= bug[T[i-1]-'a'][c];

    if (b1) adj[i].push_back({i+1, 1});
    if (b2) adj[i].push_back({j, 1 + (i*2+1 - j)});
    adj[i].push_back({i-1, 1}); // deletion
  }

  // dijkstra
  fill(D, D+L+1, INF);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({D[0] = 0, 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (D[u] != d) continue;

    for (auto [v, w]: adj[u]) {
      if (d+w < D[v]) pq.push({D[v] = d+w, v});
    }
  }

  // print ans
  if (D[L] == INF) cout << -1 << endl;
  else cout << D[L] << endl;

  ////////////////////////////////
  return 0;
}
