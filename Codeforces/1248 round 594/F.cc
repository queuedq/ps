#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 1000005

int T;
int N, M, A[MAX_N], B[MAX_N];

int parent[MAX_N];
int sizes[MAX_N];

int find(int i) {
  while (parent[i] != i) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

void join(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (x == y) { return; }
  if (sizes[x] > sizes[y]) {
    parent[y] = x;
    sizes[x] = sizes[x] + sizes[y];
  } else {
    parent[x] = y;
    sizes[y] = sizes[x] + sizes[y];
  }
}

void calc() {
  // Input
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }

  // Reset
  for (int i = 0; i < N; i++) {
    parent[i] = i;
    sizes[i] = 1;
  }

  // Join
  for (int i = 0; i < M; i++) {
    join(A[i], B[i]);
  }

  for (int i = 0; i < N; i++) {
    find(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i = 0; i < T; i++) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
