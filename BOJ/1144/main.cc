#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e8;
int N, M, A[100];
map<pair<int, vector<int>>, int> D;

vector<int> normalize(vector<int> conn) {
  int cnt = 0;
  vector<int> f(M+2);
  for (int i=0; i<M; i++) {
    if (conn[i] == 0) continue;
    if (f[conn[i]] == 0) f[conn[i]] = ++cnt;
    conn[i] = f[conn[i]];
  }
  return conn;
}

vector<int> next_group(vector<int> conn, int pos, bool b) {
  if (!b) {
    conn[pos] = 0;
  } else if (pos == 0 || conn[pos-1] == 0) {
    if (conn[pos] == 0) conn[pos] = M+1;
  } else {
    int c0 = conn[pos], c1 = conn[pos-1];
    if (c0 != 0) {
      for (int i=0; i<M; i++) {
        if (conn[i] == c0) conn[i] = c1;
      }
    }
    conn[pos] = c1;
  }
  return normalize(conn);
}

int dp(int i, vector<int> conn) {
  if (D.count({i, conn}) != 0) return D[{i, conn}];
  if (i == N*M) {
    for (int j=0; j<M; j++) {
      if (conn[j] > 1) return D[{i, conn}] = INF;
    }
    return D[{i, conn}] = 0;
  }
  
  int ans = INF;
  ans = min(ans, A[i] + dp(i+1, next_group(conn, i%M, 1)));
  if (conn[i%M] == 0 || count(conn.begin(), conn.end(), conn[i%M]) > 1) {
    ans = min(ans, dp(i+1, next_group(conn, i%M, 0)));
  } else if (count(conn.begin(), conn.end(), 0) == M-1) {
    ans = min(ans, 0);
  }

  return D[{i, conn}] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N*M; i++) cin >> A[i];

  vector<int> conn(M);
  cout << dp(0, conn) << endl;

  ////////////////////////////////
  return 0;
}
