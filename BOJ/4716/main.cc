#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A, B;

struct Balloon {
  int da, db;
  bool operator <(Balloon X) const { return abs(da-db) < abs(X.da-X.db); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> N >> A >> B;
    if (N == 0) break;
    vector<Balloon> X;

    for (int i=0; i<N; i++) {
      int K, da, db; cin >> K >> da >> db;
      for (int j=0; j<K; j++) X.push_back({da, db});
    }
    sort(X.rbegin(), X.rend());

    int ans = 0;
    for (auto [da, db]: X) {
      if (A == 0) { ans += db; B--; continue; }
      if (B == 0) { ans += da; A--; continue; }

      if (da < db) { ans += da; A--; }
      else { ans += db; B--; }
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
