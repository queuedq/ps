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
int N, A[MN], pos[MN], used[MN];
vector<pii> ans;

int pivot() {
  for (int e=1; e<=N; e++) if (!used[e] && pos[e] != e) return e;
  return 0;
}

vector<int> get_unused() {
  vector<int> X;
  for (int e=1; e<=N; e++) if (!used[e]) X.push_back(e);
  return X;
}

// swap elements a, b (not indices)
void do_swap(int a, int b) {
  ans.push_back({a, b});
  swap(A[pos[a]], A[pos[b]]);
  swap(pos[a], pos[b]);
}

bool solve_sorted();

bool solve() {
  // pivot = next element to sort = unused element in wrong place
  int p = pivot();
  if (!p) return solve_sorted();
  used[p] = 1;

  // swap to other places
  for (int e=1; e<=N; e++) {
    if (used[e] || e == A[p]) continue;
    do_swap(p, e);
  }
  do_swap(p, A[p]);

  // recurse
  return solve();
}

bool solve_sorted() {
  vector<int> X = get_unused();
  int cnt = sz(X);
  if (cnt % 4 == 2 || cnt % 4 == 3) return false;
  if (cnt == 1) return true;

  // 1(234567)8 -> (234567)18
  for (int i=1; i<cnt-1; i++) do_swap(X[0], X[i]);
  // 2(34567)18 -> 8(34567)12 -> 1(34567)82
  do_swap(X[1], X[cnt-1]);
  do_swap(X[0], X[cnt-1]);
  // 1(3456)782 -> 12(3456)87
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
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    pos[A[i]] = i;
  }

  bool ok = solve();
  if (ok) {
    for (auto [a, b]: ans) cout << a << " " << b << endl;
  } else {
    cout << "no" << endl;
  }

  ////////////////////////////////
  return 0;
}
