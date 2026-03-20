#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
lld N, x[MN], a[MN], tmp[MN];
unordered_set<lld> T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> x[i] >> a[i];

  // divisors of different colors distances
  for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
      if (a[i] == a[j]) continue;
      lld diff = abs(x[i] - x[j]);
      
      for (int d=1; d<=sqrt(diff); d++) {
        if (diff % d == 0) {
          T.insert(d);
          T.insert(diff / d);
        }
      }
    }
  }

  // check if smaller period exists
  for (int t=1; t<=N; t++) {
    if (T.count(t)) continue;

    fill(tmp, tmp+t, 0);
    for (int i=0; i<N; i++) tmp[(x[i]%t+t) % t] = a[i];
    if (count(tmp, tmp+t, 0)) continue;

    for (int u=1; u<t; u++) {
      if (t % u != 0) continue;
      
      bool smaller = true;
      for (int i=0; i<t-u; i++) {
        if (tmp[i] != tmp[i+u]) { smaller = false; break; }
      }
      if (smaller) { T.insert(t); break; }
    }
  }

  // answer
  lld sum = 0;
  for (auto t: T) sum += t;
  cout << T.size() << " " << sum << endl;

  ////////////////////////////////
  return 0;
}
