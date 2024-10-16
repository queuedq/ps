#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
int N, M;
char A[MN][MN];
vector<pii> adj[MN];
string S, T;

bool dfs(int u, bool c) { // 1: '/', 0: '\\'
  if (S[u]) return S[u] == (c ? '/' : '\\');
  S[u] = (c ? '/' : '\\');

  bool ok = 1;
  for (auto [v, w]: adj[u]) ok &= dfs(v, c^w);
  return ok;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) cin >> A[i][j];
  }

  // build graph
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      for (int k=j+1; k<=M; k++) {
        if (A[i][j] != '?' && A[i][k] != '?') {
          int w = A[i][j] != A[i][k];
          adj[j].push_back({k, w});
          adj[k].push_back({j, w});
        }
      }
    }
  }
  
  // get first line
  S.resize(M+1);
  bool ok = 1;
  for (int j=1; j<=M; j++) if (A[1][j] != '?') {
    ok &= dfs(j, A[1][j] == '/');
  }
  for (int j=1; j<=M; j++) if (!S[j]) {
    ok &= dfs(j, 1);
  }

  if (!ok) return cout << "impossible" << endl, 0;

  T.resize(M+1); // inverted
  for (int j=1; j<=M; j++) T[j] = S[j] ^ '/' ^ '\\';
  if (S[1] == '\\') swap(S, T); // S < T

  // construct
  for (int i=1; i<=N; i++) {
    bool flag = 1; // use S?
    for (int j=1; j<=M && flag; j++) {
      flag &= (A[i][j] == '?' || A[i][j] == S[j]);
    }
    for (int j=1; j<=M; j++) A[i][j] = flag ? S[j] : T[j];
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) cout << A[i][j];
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
