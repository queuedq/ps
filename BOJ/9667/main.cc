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
int N, phi[MN];
vector<int> divisors[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  iota(phi, phi+MN, 0);
  for (int d=1; d<MN; d++) {
    divisors[d].push_back(d);
    for (int m=d*2; m<MN; m+=d) {
      divisors[m].push_back(d);
      phi[m] -= phi[d];
    }
  }

  vector<int> D;
  cin >> N; N++;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    for (auto d: divisors[a]) D.push_back(d);
  }
  sort(all(D));
  D.erase(unique(all(D)), D.end());

  lld ans = 0;
  for (auto d: D) ans += phi[d];
  cout << ans-1 << endl;

  ////////////////////////////////
  return 0;
}
