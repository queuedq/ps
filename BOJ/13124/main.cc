#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, Q, A[MN];

bool check() {
  return (A[2] == 1 && A[1] == 3 && A[N] == 2) ||
    (A[1] == 2 && A[3] == 1 && A[2] == N) ||
    (A[N-1] == N && A[N] == N-2 && A[1] == N-1) ||
    (A[N] == N-1 && A[N-2] == N && A[N-1] == 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  cin >> Q;
  for (int q=1; q<=Q; q++) {
    int x, y; cin >> x >> y;
    swap(A[x], A[y]);
    cout << (check() ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
