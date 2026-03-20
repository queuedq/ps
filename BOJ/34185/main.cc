#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, A[MN], used[MN];
vector<pii> ans;

int pivot() {
  for (int i=1; i<=N; i++) if (!used[i] && A[i] != i) return i;
  return 0;
}

vector<int> get_unused() {
  vector<int> X;
  for (int i=1; i<=N; i++) if (!used[i]) X.push_back(i);
  return X;
}

// swap elements at i, j
void do_swap(int i, int j) {
  ans.push_back({i, j});
  swap(A[i], A[j]);
}

bool solve_sorted();

bool solve() {
  // pivot = next index to sort = unused index with wrong element
  int p = pivot();
  if (!p) return solve_sorted();
  used[p] = 1;

  // find pos of element p
  int j = 1;
  for (; j<=N; j++) if (A[j] == p) break;

  // swap with other indices
  for (int i=1; i<=N; i++) {
    if (used[i] || i == j) continue;
    do_swap(p, i);
  }
  do_swap(p, j);

  // recurse
  return solve();
}

bool solve_sorted() {
  vector<int> X = get_unused();
  int cnt = sz(X);
  if (cnt % 4 == 2 || cnt % 4 == 3) return false;
  if (cnt == 1) return true;

  // (123456)78 -> 7(123456)8
  for (int i=1; i<cnt-1; i++) do_swap(X[0], X[i]);
  // 71(23456)8 -> 78(23456)1 -> 18(23456)7
  do_swap(X[1], X[cnt-1]);
  do_swap(X[0], X[cnt-1]);
  // 18(23456)7 -> 1(23456)87
  for (int i=cnt-2; i>=2; i--) do_swap(X[1], X[i]);

  used[X[0]] = used[X[1]] = 1;

  // recurse
  return solve();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  bool ok = solve();
  cout << ok << endl;
  if (ok) {
    for (auto [a, b]: ans) cout << a << " " << b << endl;
  }

  ////////////////////////////////
  return 0;
}
