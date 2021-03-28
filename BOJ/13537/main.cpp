#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000

int N, A[MAX_N], M, L[MAX_M], R[MAX_M], K[MAX_M];
vector<int> merge_sort_tree[MAX_N * 4];
pair<int, int> intervals[MAX_N * 4];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> L[i];
    cin >> R[i];
    cin >> K[i];
  }
}

void build(int v, int l, int r) {
  // printf("v l r %d %d %d\n", v, l, r);
  intervals[v] = make_pair(l, r);
  if (l + 1 == r) {
    merge_sort_tree[v].push_back(A[l]);
    return;
  }
  int m = (l + r) / 2;
  build(v*2,   l, m);
  build(v*2+1, m, r);
  merge(
    merge_sort_tree[v*2].begin(), merge_sort_tree[v*2].end(),
    merge_sort_tree[v*2+1].begin(), merge_sort_tree[v*2+1].end(),
    back_inserter(merge_sort_tree[v])
  );
}

int count(int v, int l, int r, int k) {
  if (l <= get<0>(intervals[v]) && get<1>(intervals[v]) <= r) {
    auto pos = upper_bound(merge_sort_tree[v].begin(), merge_sort_tree[v].end(), k);
    return merge_sort_tree[v].end() - pos;
  } else if (r <= get<0>(intervals[v]) || l >= get<1>(intervals[v])) {
    return 0;
  }
  return count(v*2, l, r, k) + count(v*2+1, l, r, k);
}

void process_queries() {
  for (int q = 0; q < M; q++) {
    printf("%d\n", count(1, L[q] - 1, R[q], K[q]));
  }
}

int main() {
  input();
  build(1, 0, N);
  process_queries();

  return 0;
}
