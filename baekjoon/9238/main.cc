#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, cuts[MAXN];
double A[MAXN], T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  fill(cuts, cuts+N, 1);

  double ratio = *min_element(A, A+N) / *max_element(A, A+N);
  int total = 0;
  while (true) {
    int m = 0, M = 0;
    for (int j = 0; j < N; j++) {
      if (A[j]/cuts[j] > A[M]/cuts[M]) M = j;
      if (A[j]/cuts[j] < A[m]/cuts[m]) m = j;
    }
    ratio = max(ratio, (A[m]/cuts[m]) / (A[M]/cuts[M]));
    if (ratio > T) break;
    cuts[M]++;
    total++;
  }

  cout << total << endl;

  ////////////////////////////////
  return 0;
}
