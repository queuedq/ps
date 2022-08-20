#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, K;
vector<int> A;
set<int> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  A.resize(M);
  for (int i=0; i<M; i++) cin >> A[i];
  S = set(all(A));

  for (int i=0; i<K; i++) {
    int x; cin >> x;
    auto it = S.upper_bound(x);
    cout << *it << endl;
    S.erase(it);
  }

  ////////////////////////////////
  return 0;
}
