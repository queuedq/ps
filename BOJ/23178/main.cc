#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, Q;
string S;
set<int> beads;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S >> Q;
  for (int i=0; i<sz(S); i++) {
    if (S[i] == 'O') beads.insert(i+1);
  }
  for (int i=0; i<Q; i++) {
    int x; cin >> x;
    if (beads.count(x)) beads.erase(x);
    else beads.insert(x);
    int ans = min(
      *prev(beads.end()) - sz(beads),
      (N - *beads.begin() + 1) - sz(beads)
    );
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
