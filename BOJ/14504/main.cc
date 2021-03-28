#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 100'005;
const int SQRT_N = 400;
int N, M, A[MAX_N], sz = 900;
vector<int> bkt[SQRT_N];

struct Query {
  int q, i, j, k;
} Q[MAX_N];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  cin >> M;
  for (int t = 0; t < M; t++) {
    int q, i, j = 0, k; cin >> q;
    if (q == 1) cin >> i >> j >> k;
    else cin >> i >> k;
    Q[t] = {q, i-1, j, k};
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    bkt[i / sz].push_back(A[i]);
  }
  for (int i = 0; i < N/sz + 1; i++) {
    sort(bkt[i].begin(), bkt[i].end());
  }
}

void update(Query query) {
  int i = query.i, k = query.k, a = A[i];
  vector<int> &B = bkt[i / sz];
  B.erase(lower_bound(B.begin(), B.end(), a));
  B.insert(lower_bound(B.begin(), B.end(), k), k);
  A[i] = k;
}

int count(Query query) {
  auto [_, i, j, k] = query;
  int ans = 0;

  while(i < j && i % sz != 0) {
    if (A[i] > k) { ans++; }
    i++;
  }
  while(i < j && j % sz != 0) {
    j--;
    if (A[j] > k) { ans++; }
  }
  while(i < j) {
    ans += bkt[i/sz].end() - lower_bound(bkt[i/sz].begin(), bkt[i/sz].end(), k+1);
    i += sz;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  init();

  for (int i = 0; i < M; i++) {
    if (Q[i].q == 1) { cout << count(Q[i]) << endl; }
    else { update(Q[i]); }
  }

  ////////////////////////////////
  return 0;
}
