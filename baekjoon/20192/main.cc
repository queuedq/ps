#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  bool inc = false;
  int cnt = 0;
  for (int i=1; i<=N; i++) {
    if (!inc && A[i-1] < A[i]) { inc = true; cnt++; }
    if (inc && A[i-1] > A[i]) { inc = false; cnt++; }
  }

  cout << ceil(log2(cnt)) << endl;

  ////////////////////////////////
  return 0;
}
