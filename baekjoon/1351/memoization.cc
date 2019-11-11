#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
lld N, P, Q;
map<lld, lld> A;

lld getA(lld i) {
  if (A[i]) return A[i];
  A[i] = getA(i / P) + getA(i / Q);
  return A[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P >> Q;
  A[0] = 1;
  cout << getA(N) << endl;

  ////////////////////////////////
  return 0;
}
