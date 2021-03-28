#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<int> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<50; i++) {
    int x; cin >> x;
    if (x == 0) break;
    else A.push_back(x);
  }

  sort(A.begin(), A.end());

  bool found = false;
  for (int i=0; i<A.size()-2; i++) {
    if (A[i]+A[i+1] > A[i+2]) {
      cout << A[i] << " " << A[i+1] << " " << A[i+2] << endl;
      found = true;
      break;
    }
  }

  if (!found) cout << "NIE" << endl;

  ////////////////////////////////
  return 0;
}
