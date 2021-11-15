#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  int sum = 0;
  for (int i=0; i<N; i++) {
    if (sum+1 < A[i]) break;
    sum += A[i];
  }
  cout << sum+1 << endl;

  ////////////////////////////////
  return 0;
}
