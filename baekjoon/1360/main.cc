#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 105;
int N;
string A[MAXN];
int T[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    string type; cin >> type;
    if (type == "type") {
      char c; int t; cin >> c >> t;
      T[i] = t;
      A[i] = A[i-1] + c;
    } else {
      int undo, t; cin >> undo >> t;
      T[i] = t;
      int j = i;
      while (j > 0 && T[i] - T[j] <= undo) j--;
      A[i] = A[j];
    }
  }

  // for (int i=0; i<=N; i++) cout << A[i] << endl;
  cout << A[N] << endl;

  ////////////////////////////////
  return 0;
}
