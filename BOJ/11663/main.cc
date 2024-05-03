#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, X[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> X[i];
  sort(X, X+N);

  for (int i=0; i<M; i++) {
    int l, r; cin >> l >> r;
    auto li = lower_bound(X, X+N, l);
    auto ri = upper_bound(X, X+N, r);
    cout << ri - li << endl;
  }

  ////////////////////////////////
  return 0;
}
