#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
lld N, A[MN];
set<lld> S, T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  S.insert(A[0]);
  S.insert(A[0]+1);
  for (int i=1; i<N; i++) {
    for (auto x: S) {
      T.insert(gcd(x, A[i]));
      T.insert(gcd(x, A[i]+1));
    }
    swap(S, T);
    T.clear();
    assert(S.size() <= 15);
  }

  cout << *prev(S.end()) << endl;

  ////////////////////////////////
  return 0;
}
