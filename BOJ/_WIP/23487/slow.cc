#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5005;
const int MX = MN*MN/2;
int N, A[MN][MN], vst[MX], T[MX];
vector<int> adj[MX];

bool match(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;

  for (auto v: adj[u]) {
    if (!T[v] || match(T[v])) {
      T[v] = u;
      return 1;
    }
  }
  return 0;
}

void solve() {
  cin >> N;
  int V = N*(N+1)/2;
  for (int r=1; r<=N; r++) {
    string S; cin >> S;
    for (int c=1; c<=r; c++) A[r][c] = S[c-1] - '0';
  }

  // build graph (left set: downward triangles)
  int i = 1;
  for (int r=1; r<=N-1; r++) {
    for (int c=1; c<=r; c++, i++) {
      if (A[r][c]) adj[i].push_back(i); // up
      if (A[r+1][c]) adj[i].push_back(i+r); // left
      if (A[r+1][c+1]) adj[i].push_back(i+r+1); // right
    }
  }

  // match
  for (int i=1; i<=V-N; i++) {
    fill(vst, vst+V-N+1, 0);
    bool ok = match(i);
    if (!ok) { cout << "Impossible!" << endl; return; }
  }
  
  // answer
  i = 1;
  for (int r=1; r<=N; r++) {
    for (int c=1; c<=r; c++, i++) {
      if (A[r][c] == 0) cout << '-';
      else if (T[i] == i-r) cout << '1'; // left
      else if (T[i] == i-r+1) cout << '3'; // right
      else if (T[i] == i) cout << '2'; // down
      else assert(0);
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
