#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

const int MN = 300'005;
lld N, H[MN], T[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];
  for (int i=2; i<=N; i++) { cin >> T[i]; T[i] += T[i-1]; }

  int j = 1;
  set<pll> S;
  for (int i=1; i<=N; i++) {
    while (j <= N && T[j] - T[i] <= H[j]) S.insert({H[j], j++});
    D[i] = S.rbegin()->first;
    S.erase({H[i], i});
  }

  j = N;
  for (int i=N; i>=1; i--) {
    while (j >= 1 && T[i] - T[j] <= H[j]) S.insert({H[j], j--});
    D[i] = max(D[i], S.rbegin()->first);
    S.erase({H[i], i});
  }

  for (int i=1; i<=N; i++) cout << D[i] << " ";

  return 0;
}
