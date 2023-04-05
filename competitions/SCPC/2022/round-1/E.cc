#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, M, A[MN][MN], vst[MN*MN];
vector<int> t1, t2;
int idx[MN*MN], F[MN*MN];

// fenwick tree
void add(int i, lld x) {
  for (; i<=M; i += i&-i) F[i] += x;
}

lld sum(int i) { // [1, i]
  lld s = 0;
  for (; i>0; i -= i&-i) s += F[i];
  return s;
}
// ========

inline int to_int(int x, int y) { return x*N + y; }

void dfs1(int x, int y) {
  vst[to_int(x, y)] = 1;
  if (x+1 < N && A[x+1][y] && !vst[to_int(x+1, y)]) dfs1(x+1, y);
  if (y+1 < N && A[x][y+1] && !vst[to_int(x, y+1)]) dfs1(x, y+1);
  t1.push_back(to_int(x, y));
}

void dfs2(int x, int y) {
  vst[to_int(x, y)] = 1;
  if (y+1 < N && A[x][y+1] && !vst[to_int(x, y+1)]) dfs2(x, y+1);
  if (x+1 < N && A[x+1][y] && !vst[to_int(x+1, y)]) dfs2(x+1, y);
  t2.push_back(to_int(x, y));
}

lld solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<N; j++) A[i][j] = S[j] == '.';
  }

  fill(vst, vst+N*N, 0);
  dfs1(0, 0);
  fill(vst, vst+N*N, 0);
  dfs2(0, 0);

  M = t1.size();
  for (int i=0; i<M; i++) idx[t1[i]] = i+1; // 1-based

  lld ans = 0;
  for (int i=M-1; i>=0; i--) {
    ans += sum(idx[t2[i]]);
    add(idx[t2[i]], 1);
  }

  return ans;
}

void reset() {
  t1.clear();
  t2.clear();
  fill(F, F+M+1, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    reset();
    cout << "Case #" << t << endl;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
