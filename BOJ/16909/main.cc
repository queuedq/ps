#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e6 + 5;
int N;
bool seen[MAX_N];
pll A[MAX_N];

struct DSU {
  int parent[MAX_N], size[MAX_N];

  DSU() {
    reset();
  }

  void reset() {
    for (int i = 0; i < MAX_N; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  int getSize(int x) {
    return size[find(x)];
  }

  void join(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] = size[x] + size[y];
  }
} dsu;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    lld w; cin >> w;
    A[i] = {w, i + 1};
  }
  sort(A, A + N);
}

lld calc() {
  lld ans = 0;

  for (int i = 0; i < N; i++) {
    pll a = A[i];
    lld w = a.first, idx = a.second;
    lld l = 1, r = 1;
    seen[idx] = true;
    if (seen[idx - 1]) {
      l = dsu.getSize(idx - 1) + 1;
      dsu.join(idx, idx - 1);
    }
    if (seen[idx + 1]) {
      r = dsu.getSize(idx + 1) + 1;
      dsu.join(idx, idx + 1);
    }
    ans += w * l * r;
  }

  dsu.reset();
  fill(seen, seen + MAX_N, false);

  for (int i = N - 1; i >= 0; i--) {
    pll a = A[i];
    lld w = a.first, idx = a.second;
    lld l = 1, r = 1;
    seen[idx] = true;
    if (seen[idx - 1]) {
      l = dsu.getSize(idx - 1) + 1;
      dsu.join(idx, idx - 1);
    }
    if (seen[idx + 1]) {
      r = dsu.getSize(idx + 1) + 1;
      dsu.join(idx, idx + 1);
    }
    ans -= w * l * r;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  cout << calc() << endl;

  ////////////////////////////////
  return 0;
}
