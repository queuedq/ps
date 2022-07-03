#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, x[MN], y[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> x[i] >> y[i];

  pii ans = {INT_MAX, 0};
  for (int i=0; i<N; i++) {
    pii dst = {0, i};
    for (int j=0; j<N; j++) {
      dst = max(dst, {(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]), i});
    }
    ans = min(ans, dst);
  }

  cout << x[ans.second] << " " << y[ans.second] << endl;

  ////////////////////////////////
  return 0;
}
