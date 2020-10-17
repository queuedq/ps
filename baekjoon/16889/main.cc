#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
map<pair<int, lld>, int> D;
int nimber[61];

int getNimber(int N, lld used) {
  used &= (1LL<<N) - 1;
  if (N == 0) return 0;
  if (D.count({N, used})) return D[{N, used}];

  unordered_set<int> nimbers;
  for (int i=1; i<=N; i++) {
    if (used & (1LL<<i-1)) continue;
    nimbers.insert(getNimber(N-i, used ^ (1LL<<i-1)));
  }

  if (nimbers.empty()) return 0;
  for (int i=0; ; i++) {
    if (nimbers.count(i) == 0) return D[{N, used}] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<=60; i++) {
    nimber[i] = getNimber(i, 0);
  }

  int N; cin >> N;
  int ans = 0;
  while (N--) {
    int a; cin >> a;
    ans ^= nimber[a];
  }

  if (ans == 0) cout << "cubelover" << endl;
  else cout << "koosaga" << endl;

  ////////////////////////////////
  return 0;
}
