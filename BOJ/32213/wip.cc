#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int A[100][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) {
      vector<int> G(500);
      for (int k=0; k<i; k++) G[A[k][j]] = 1;
      for (int k=0; k<j; k++) G[A[i][k]] = 1;
      if (i != 0 && j != 0) G[A[0][i^j]] = 1;
      while (G[A[i][j]]) A[i][j]++;
    }
  }

  for (int i=0; i<=32; i++) {
    for (int j=0; j<=32; j++) {
      cout << setw(3) << A[i][j];
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
