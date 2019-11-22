#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5 + 5;
lld N, M;
lld F[MAX_N];
pll S[MAX_N];

struct DisjointSet {
  int parent[MAX_N];
  lld size[MAX_N];

  DisjointSet() {
    for (int i = 0; i < MAX_N; i++) {
      parent[i] = i;
      size[i] = 0;
    }
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  void join(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
  }

  lld getSize(int x) {
    return size[find(x)];
  }
} dj;

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    lld sp;
    cin >> F[i] >> sp;
    S[i] = {sp, i};
  }
  sort(S, S + N);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  lld minSpice = LLONG_MAX;
  for (int i = 0; i < N; i++) {
    pll sp = S[i];
    lld spice = sp.first, j = sp.second;
    dj.size[j] = F[j];
    if (j - 1 >= 0 && dj.size[j - 1] > 0) {
      dj.join(j, j - 1);
    }
    if (j + 1 < N && dj.size[j + 1] > 0) {
      dj.join(j, j + 1);
    }
    if (dj.getSize(j) >= M) {
      minSpice = spice;
      break;
    }
  }

  cout << minSpice << endl;

  ////////////////////////////////
  return 0;
}
