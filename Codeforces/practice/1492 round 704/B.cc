#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, P[MN], pmx[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=1; i<=N; i++) {
      cin >> P[i];
      pmx[i] = max(pmx[i-1], P[i]);
    }

    int j = N;
    for (int i=N; i>=1; i--) {
      if (P[i] == pmx[i]) {
        for (int k=i; k<=j; k++) cout << P[k] << " ";
        j = i-1;
      }
    }

    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
