#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
pii diag[5] = {{1, 3}, {2, 4}, {3, 5}, {4, 1}, {5, 2}};
vector<int> D;

int solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    int u, v; cin >> u >> v;
    for (int j=0; j<5; j++)
      if (pii(u, v) == diag[j] || pii(v, u) == diag[j])
        D.push_back(j);
  }

  if (N == 10) return -1;
  if (D.size() == 5) return 2; // 5 diag: always 2 moves
  // <= 4 diag: always <= 1 move
  for (int i: D)
    for (int j: D)
      if (j-i == 1 || j-i == 4) return 1;
  return 0;
}

int main() {
  cout << solve() << endl;
  return 0;
}
