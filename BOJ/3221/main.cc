#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 70'005;
int L, T, N;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> T >> N;
  for (int i=0; i<N; i++) {
    int x, d; char dir; cin >> x >> dir;
    d = dir == 'D' ? 1 : -1;

    x = (x + T * d) % (L*2);
    x = (x + L*2) % (L*2);
    if (x >= L) x = L*2 - x;

    A[i] = {x, d};
  }

  sort(A, A+N);
  for (int i=0; i<N; i++) cout << A[i].first << " ";

  ////////////////////////////////
  return 0;
}
