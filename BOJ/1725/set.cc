#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
pll A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A[i] = {a, i};
  }

  sort(A, A+N);

  set<int> S;
  S.insert(-1);
  S.insert(N);

  lld ans = 0;
  for (int i=0; i<N; i++) {
    auto [a, j] = A[i];
    auto it = S.lower_bound(j);
    int l = *prev(it), r = *it;
    S.insert(j);

    ans = max(ans, a * (r-l-1));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
