#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 51;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N, S[MN*MN], T[MN*MN], vst[MN*MN], xcnt;
char A[MN][MN];
vector<int> adj[MN*MN];

bool oob(int i, int j) { return i < 0 || i >= N || j < 0 || j >= N; }

bool match(int u) {
  int x = u/N, y = u%N;
  if ((x+y)&1 || vst[u]) return false;
  vst[u] = true;

  for (int d=0; d<4; d++) {
    int z = x+dx[d], w = y+dy[d], v = z*N+w;
    if (oob(z, w)) continue;

    bool edge = (A[x][y] == '.' && A[z][w] == 'o') || (A[x][y] == 'o' && A[z][w] == '.');
    if (!edge) continue;
    
    if (T[v] == -1 || match(T[v])) return S[u] = v, T[v] = u, true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    for (int j=0; j<N; j++) {
      if (A[i][j] == 'x') xcnt++;
    }
  }

  fill(S, S+N*N, -1);
  fill(T, T+N*N, -1);

  int m = 0;
  for (int u=0; u<N*N; u++) {
    fill(vst, vst+N*N, 0);
    m += match(u);
  }

  cout << N*N - xcnt - m << endl;

  ////////////////////////////////
  return 0;
}
