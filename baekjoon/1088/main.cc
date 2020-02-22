#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
int N, M, cuts[MAXN];
double A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> M;
  fill(cuts, cuts+N, 1);

  double ans = INT_MAX;
  for (int i = 0; i <= M; i++) {
    int m = 0, M = 0;
    for (int j = 0; j < N; j++) {
      if (A[j]/cuts[j] > A[M]/cuts[M]) M = j;
      if (A[j]/cuts[j] < A[m]/cuts[m]) m = j;
    }
    ans = min(ans, A[M]/cuts[M] - A[m]/cuts[m]);
    cuts[M]++;
  }

  cout << fixed << setprecision(12) << ans << endl;

  ////////////////////////////////
  return 0;
}
