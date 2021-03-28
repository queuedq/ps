#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int M, N, L, A[MAXN], x[MAXN], y[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N >> L;
  for (int i=0; i<M; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> x[i] >> y[i];

  sort(A, A+M);

  int cnt = 0;
  for (int i=0; i<N; i++) {
    int j = lower_bound(A, A+M, x[i]) - A;
    if (j-1 >= 0 && y[i] + x[i] - A[j-1] <= L) cnt++;
    else if (j < M && y[i] + A[j] - x[i] <= L) cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
