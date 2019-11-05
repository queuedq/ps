#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 100000
lld T, N, M, PO, PE, QO, QE;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int t = 0; t < T; t++) {
    PO = 0, PE = 0, QO = 0; QE = 0;

    cin >> N;
    for (int i = 0 ; i < N; i++) {
      lld p;
      cin >> p;
      if (p % 2 == 0) { PE++; }
      if (p % 2 == 1) { PO++; }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
      lld q;
      cin >> q;
      if (q % 2 == 0) { QE++; }
      if (q % 2 == 1) { QO++; }
    }

    cout << PE * QE + PO * QO << endl;
  }



  ////////////////////////////////
  return 0;
}
