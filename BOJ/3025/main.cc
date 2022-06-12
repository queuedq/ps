#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MR = 30005;
const int MC = 35;
int R, C, N;
char A[MR][MC];
vector<pii> path[MC];

pii nxt(pii pos) {
  auto [r, c] = pos;
  if (r == R || A[r+1][c] == 'X') return pos;
  if (A[r+1][c] == '.') return {r+1, c};
  if (c > 1 && A[r][c-1] == '.' && A[r+1][c-1] == '.') return {r+1, c-1};
  if (c < C && A[r][c+1] == '.' && A[r+1][c+1] == '.') return {r+1, c+1};
  return pos;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> R >> C;
  for (int i=1; i<=R; i++) cin >> (A[i]+1);
  for (int i=1; i<=C; i++) path[i].push_back({0, i});

  cin >> N;
  for (int i=0; i<N; i++) {
    int x; cin >> x;
    while (true) {
      auto [r, c] = path[x].back();
      if (A[r][c] != 'O') break;
      path[x].pop_back();
    }
    while (true) {
      pii p1 = path[x].back();
      pii p2 = nxt(p1);
      if (p1 == p2) break;
      path[x].push_back(p2);
    }
    auto [r, c] = path[x].back();
    A[r][c] = 'O';
  }

  for (int i=1; i<=R; i++) cout << (A[i]+1) << endl;

  ////////////////////////////////
  return 0;
}
