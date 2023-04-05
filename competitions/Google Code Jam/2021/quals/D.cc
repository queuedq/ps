#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, Q;

int query(int a, int b, int c) {
  cout << a << " " << b << " " << c << endl;
  int m; cin >> m;
  return m;
}

void solve(vector<int> &A) {
  if (A.size() <= 2) return;

  int a = A[0], b = A[1];
  vector<int> L, M, R;
  for (int i=2; i<A.size(); i++) {
    int m = query(a, b, A[i]);
    if (m == a) L.push_back(A[i]);
    if (m == A[i]) M.push_back(A[i]);
    if (m == b) R.push_back(A[i]);
  }

  solve(L);
  solve(M);
  solve(R);

  if (L.size() >= 2 && query(a, L[0], L[1]) == L[0]) reverse(L.begin(), L.end());
  if (M.size() >= 2 && query(a, M[0], M[1]) == M[1]) reverse(M.begin(), M.end());
  if (R.size() >= 2 && query(a, R[0], R[1]) == R[1]) reverse(R.begin(), R.end());

  A.clear();
  for (int x: L) A.push_back(x);
  A.push_back(a);
  for (int x: M) A.push_back(x);
  A.push_back(b);
  for (int x: R) A.push_back(x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  cin >> N >> Q;
  while (T--) {
    vector<int> A;
    for (int i=1; i<=N; i++) A.push_back(i);
    solve(A);
    for (int x: A) cout << x << " ";
    cout << endl;
    bool _; cin >> _;
  }

  ////////////////////////////////
  return 0;
}
