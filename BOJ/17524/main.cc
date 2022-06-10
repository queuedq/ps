#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, K, t[MN], w[MN], a=100;

int time(int i, int T) { return 30 + (t[i]-T) * w[i]; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> t[i] >> w[i];
    a = min(a, t[i]);
  }

  vector<pii> X;
  for (int u=0; u<N; u++) X.push_back({time(u, a), u});
  sort(X.rbegin(), X.rend());
  int ans = X.front().first;

  int b = 100;
  for (int i=0; i<N-1; i++) { // 2nd group: X[..i]
    b = min(b, t[X[i].second]);
    vector<pii> Y;
    for (int j=0; j<=i; j++) Y.push_back({time(X[j].second, b), X[j].second});
    sort(Y.rbegin(), Y.rend());

    if (K >= 2) ans = min(ans, X[i+1].first + Y.front().first);

    int c = 100, z = 0;
    for (int j=0; j<i; j++) { // 3rd group: Y[..j]
      int u = Y[j].second;
      if (t[u] < c) { // recalc z (<= 60 times)
        c = t[u], z = 0;
        for (int k=0; k<=j; k++) z = max(z, time(Y[k].second, c));
      } else {
        z = max(z, time(u, c));
      }

      if (K >= 3) ans = min(ans, X[i+1].first + Y[j+1].first + z);
    }
  }
  
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
