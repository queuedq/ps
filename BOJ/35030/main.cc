#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int prime[MN], special[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int x=2; x<MN; x++) {
    prime[x] = 1;
    for (int d=2; d*d<=x; d++) {
      if (x%d == 0) { prime[x] = 0; break; }
    }
  }

  for (int n=1; n<MN; n++) {
    if (!prime[n+1]) continue;
    special[n] = 1;

    for (int p=10;; p*=10) {
      int a = n/p, b = n%p;
      if (a == 0) break;
      if (!prime[a*b+1]) { special[n] = 0; break; }
    }
  }

  for (int n=1; n<MN; n++) {
    special[n] += special[n-1];
  }

  int T, N; cin >> T;
  while (T--) {
    cin >> N;
    cout << special[N] << endl;
  }

  ////////////////////////////////
  return 0;
}
