#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 305;
int N, A[MAXN], D[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  D[0] = 0;
  D[1] = A[1];
  D[2] = A[1]+A[2];

  for (int i=1; i<=N; i++) {
    D[i] = max(D[i-2] + A[i], D[i-3] + A[i-1]+A[i]);
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
