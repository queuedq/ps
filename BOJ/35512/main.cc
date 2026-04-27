#include <bits/stdc++.h>
#include <cctype>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 30303;
const int ML = 101;
int L, N;
string S[MN], ans;
vector<pii> adj[MN + ML];
bool vst[MN + ML], val[MN + ML];

void make_edge(int u, int v, int w) {
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}

bool dfs(int u, int c, vector<int> &comp) {
  vst[u] = 1, val[u] = c;
  if (u < N) comp.push_back(u);

  bool ok = true;
  for (auto [v, w]: adj[u]) {
    if (!vst[v]) ok &= dfs(v, c ^ w, comp);
    else if (val[v] != (c ^ w)) ok = false;
  }
  return ok;
}

void apply(string &A, string &B) {
  for (int k=0; k<L; k++) {
    if (B[k] != '.') A[k] = B[k];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> L >> N;
  for (int i=0; i<N; i++) cin >> S[i];

  ans = string(L, '.');

  // build graph
  for (int k=0; k<L; k++) {
    set<char> colors;
    for (int i=0; i<N; i++) {
      if (S[i][k] != '.') colors.insert(S[i][k]);
      if (S[i][L-1-k] != '.') colors.insert(S[i][L-1-k]);
    }

    if (sz(colors) > 2) { cout << "IMPOSSIBLE\n"; return 0; }

    if (sz(colors) == 2) {
      // make edges
      char a = *colors.begin(), b = *colors.rbegin();
      for (int i=0; i<N; i++) {
        // y_k (node N+k) = 0: a on segment k, 1: a on segment L-1-k
        if (S[i][k] == a) make_edge(i, N+k, 0);
        if (S[i][L-1-k] == a) make_edge(i, N+k, 1);
        if (S[i][k] == b) make_edge(i, N+k, 1);
        if (S[i][L-1-k] == b) make_edge(i, N+k, 0);
      }
    }
  }

  // find components
  for (int i=0; i<N; i++) {
    if (vst[i]) continue;
    vector<int> comp;
    bool ok = dfs(i, 0, comp);

    if (!ok) { cout << "IMPOSSIBLE\n"; return 0; }

    // reconstruct snake for this component
    string snake(L, '.');
    for (int i: comp) {
      string cur = S[i];
      if (val[i]) reverse(all(cur));
      apply(snake, cur);
    }

    // apply snake to answer
    char l = snake[0], r = snake[L-1];
    if (l != '.' || r != '.') { // direction known
      bool both_heads = isupper(l) && isupper(r);
      bool both_tails = islower(l) && islower(r);
      if (both_heads || both_tails) { cout << "IMPOSSIBLE\n"; return 0; }

      if (islower(l) || isupper(r)) reverse(all(snake));
      apply(ans, snake);

    } else { // direction unknown
      for (int k=0; k<L; k++) {
        if (snake[k] == '.') continue;
        if (snake[k] == snake[L-1-k]) ans[k] = snake[k];
      }
    }
  }

  // print answer
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
