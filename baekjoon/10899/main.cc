#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int P, N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> P >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  sort(A, A+N);

  int t = 0, cnt = 0;
  for (int i=0; i<N; i++) {
    t += A[i];
    if (t >= P) break;
    cnt++;
  }

  lld penalty = 0;
  t = P-1;
  for (int i=0; i<cnt; i++) {
    penalty += t;
    t -= A[i];
  }

  cout << cnt << " " << penalty << endl;

  ////////////////////////////////
  return 0;
}
