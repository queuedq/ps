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
int N, A[MN], proto[MN];
vector<int> adj[MN];
// M/W group = nodes reachable by My.../We... protocols
// I doesn't connect to prev siblings' M/W group
// M doesn't connect to later siblings' M/W group
int D[MN][2]; // D[u][a] / a: select node in u's M/W group?
int E[MN][2]; // E[v][b] / b: select node in prev siblings' M/W group?

void dp(int u) {
  for (auto v: adj[u]) dp(v);

  // D[u][0]
  for (auto v: adj[u]) {
    if (proto[v] == 0) D[u][0] += max(D[v][0], D[v][1]); // I
    if (proto[v] == 1) D[u][0] += D[v][0]; // M
    if (proto[v] == 2) D[u][0] += D[v][0]; // W
  }

  // D[u][1], select u
  D[u][1] = A[u];
  for (auto v: adj[u]) {
    if (proto[v] == 0) D[u][1] += D[v][0]; // I
    if (proto[v] == 1) D[u][1] += max(D[v][0], D[v][1]); // M
    if (proto[v] == 2) D[u][1] += D[v][0]; // W
  }
  
  // D[u][1], don't select u
  int prv = N;
  for (auto v: adj[u]) {
    for (int b: {0, 1}) {
      for (int c: {0, 1}) { // choose node in v's M/W group?

        if (proto[v] == 0) { // I
          E[v][b|c] = max(E[v][b|c], E[prv][b] + D[v][c]);
        }
        if (proto[v] == 1) { // M
          if (b && c) continue; // conflict
          E[v][b] = max(E[v][b], E[prv][b] + D[v][c]);
        }
        if (proto[v] == 2) { // W
          if (b && c) continue; // conflict
          E[v][b|c] = max(E[v][b|c], E[prv][b] + D[v][c]);
        }

      }
    }
    prv = v;
  }

  D[u][1] = max({D[u][1], E[prv][0], E[prv][1]});
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=1; i<N; i++) {
    int h; cin >> h >> proto[i];
    adj[h].push_back(i);
  }

  dp(0);
  cout << D[0][1] << endl;

  ////////////////////////////////
  return 0;
}
