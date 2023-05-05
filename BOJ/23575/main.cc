#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld X[3];
vector<pii> ans;

void pour(int s, int t) {
  X[s] -= X[t];
  X[t] += X[t];
  ans.push_back({s+1, t+1});
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int i=0; i<3; i++) cin >> X[i];
  
  while (1) {
    int ord[] = {0, 1, 2};
    sort(ord, ord+3, [&](int i, int j) { return X[i] < X[j]; });
    auto [a, b, c] = ord;
    if (X[a] == 0) break;

    lld q = X[b] / X[a], r = X[b] % X[a];
    if (r <= X[a] / 2) {
      while (q > 0) {
        if (q & 1) pour(b, a);
        else pour(c, a);
        q /= 2;
      }
    } else {
      q++;
      while (q > 1) {
        if (q & 1) pour(b, a);
        else pour(c, a);
        q /= 2;
      }
      pour(a, b);
    }
  }

  cout << sz(ans) << endl;
  for (auto [s, t]: ans) cout << s << " " << t << endl;

  ////////////////////////////////
  return 0;
}
