#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, A[MN*2];
vector<int> C[MN*2]; // candidate numbers passed to subtree
int P[MN*2]; // should check parent?

int get_candidate(int u) {
  int mn = N+1;
  if (sz(C[u])) mn = min(mn, *min_element(all(C[u])));
  if (P[u]) mn = min(mn, get_candidate(u/2));
  return mn;
}

void remove_candidate(int u, int a) {
  auto it = find(all(C[u]), a);
  if (it != C[u].end()) { C[u].erase(it); return; }
  if (P[u]) { P[u] = 0; remove_candidate(u/2, a); }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=N+1; i<=N*2+1; i++) A[i] = N+1;

  for (int u=1; u<=N; u++) {
    int a = A[u] ? A[u] : get_candidate(u);
    int b = A[u*2], c = A[u*2+1];
    int mn = min({a, b, c});

    if (mn == a) {
      // use candidate
      remove_candidate(u, a);

      A[u] = a;
    } else if (mn == b) {
      // pass candidate to left
      if (A[u] == 0) P[u*2] = 1;

      swap(A[u], A[u*2]);
    } else {
      // pass candidates to both
      if (A[u] != 0) C[u].push_back(a);
      C[u].push_back(b);
      P[u*2] = P[u*2+1] = 1;

      A[u] = c;
      A[u*2] = A[u*2+1] = 0;
    }
  }

  for (int u=1; u<=N; u++) cout << A[u] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
