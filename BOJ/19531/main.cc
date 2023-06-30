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
int N;
vector<int> S[MN], fail[MN];

struct Node {
  int next[4], link;
  lld w;
};

vector<Node> t(1);
int leaf[MN];

int add(int u, int c) {
  if (t[u].next[c]) return t[u].next[c];
  int v = sz(t);
  t.push_back({});
  t[u].next[c] = v;
  return v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  for (int i=0; i<N; i++) {
    string X; cin >> X;
    S[i].resize(sz(X));
    for (int j=0; j<sz(X); j++) {
      if (X[j] == 'A') S[i][j] = 0;
      if (X[j] == 'C') S[i][j] = 1;
      if (X[j] == 'G') S[i][j] = 2;
      if (X[j] == 'T') S[i][j] = 3;
    }
  }

  // kmp failure
  // we will sum weight over all suffixes of node
  // weight must be `dep - fail[dep]`,
  // so that only `dep` remains after summation
  for (int i=0; i<N; i++) {
    fail[i].resize(sz(S[i])+1);
    for (int j=1; j<sz(S[i]); j++) {
      int p = fail[i][j];
      while (p && S[i][p] != S[i][j]) p = fail[i][p];
      if (S[i][p] == S[i][j]) p++;
      fail[i][j+1] = p;
    }
  }

  // build trie
  for (int i=0; i<N; i++) {
    int u = 0;
    for (int j=0; j<sz(S[i]); j++) {
      u = add(u, S[i][j]);
      t[u].w += j+1 - fail[i][j+1]; // will cancel out
    }
    t[u].w = 0; // only proper prefix
    leaf[i] = u;
  }

  // aho-corasick
  queue<int> Q;
  for (int c=0; c<4; c++) {
    int u = t[0].next[c];
    if (!u) continue;
    Q.push(u);
  }

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    for (int c=0; c<4; c++) {
      int v = t[u].next[c];
      if (!v) continue;
      int p = t[u].link;
      while (p && !t[p].next[c]) p = t[p].link;
      if (t[p].next[c]) p = t[p].next[c];

      t[v].link = p;
      t[v].w += t[p].w;
      Q.push(v);
    }
  }

  // match
  lld ans = 0;
  for (int i=0; i<N; i++) ans += t[leaf[i]].w;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
