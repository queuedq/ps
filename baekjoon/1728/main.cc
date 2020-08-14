#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 505;
lld N, A[MAXN][MAXN];
unordered_map<lld, bool> has[MAXN];
bool matched[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N+1; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
      has[i][A[i][j]] = true;
    }
  }

  sort(A[0], A[0]+N);

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (matched[j]) continue;
      lld v = A[1][j] - A[0][i];
      bool ok = true;
      for (int k=1; k<N+1; k++) {
        if (!has[k][A[0][i] + v*k]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << A[0][i] << " " << A[1][j] - A[0][i] << endl;
        matched[j] = true;
        break;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
