#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, A[MAXN], D[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = 0;
  for (int i=0; i<N; i++) {
    D[A[i]] = D[A[i]-1]+1;
    ans = max(ans, D[A[i]]);
  }

  cout << N - ans << endl;

  ////////////////////////////////
  return 0;
}
