#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int MOD = 20'070'713;
int N, D[MN];
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i].Y >> A[i].X;
  sort(A+1, A+N+1);

  D[0] = 1;
  for (int i=1; i<=N; i++) {
    int j = lower_bound(A+1, A+N+1, pii(A[i].Y, 0)) - A - 1;
    D[i] = (D[i-1] + D[j]) % MOD;
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
