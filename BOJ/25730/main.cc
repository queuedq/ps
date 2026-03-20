#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, A, L, R;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> A >> L >> R;
  if (A/N < L) { cout << "NO" << endl; return 0; }
  for (int w=1; w<=N; w++) {
    if (A%w == 0 && L <= A/w && A/w <= R) {
      cout << "YES" << endl;
      for (int i=1; i<=w; i++) cout << A/w << " ";
      for (int i=w+1; i<=N; i++) cout << L << " ";
      return 0;
    }
  }
  cout << "NO" << endl;

  ////////////////////////////////
  return 0;
}
