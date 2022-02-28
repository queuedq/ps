#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, M, A[MN][MN];

bool solve() {
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
  }

  for (int i=0; i<N-1; i++) {
    for (int j=0; j<M-1; j++) {
      if (A[i][j] + A[i+1][j+1] > A[i][j+1] + A[i+1][j]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << (solve() ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
