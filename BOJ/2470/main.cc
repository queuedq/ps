#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  int a = A[0], b = A[1];

  for (int i=0; i<N; i++) {
    int j = lower_bound(A, A+N, -A[i]) - A;
    if (j < N && j != i && abs(A[i]+A[j]) < abs(a+b)) {
      a = A[i];
      b = A[j];
    }
    if (j-1 >= 0 && j-1 != i && abs(A[i]+A[j-1]) < abs(a+b)) {
      a = A[i];
      b = A[j-1];
    }
  }

  cout << min(a, b) << " " << max(a, b) << endl;

  ////////////////////////////////
  return 0;
}
