#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  cout << N*N+1 << endl;

  for (int i=1; i<=N; i++) {
    cout << i << " " << i << " ";
    for (int j=i+2; j<=N; j++) {
      cout << j << " " << i << " ";
    }
  }
  for (int i=N-1; i>=1; i--) {
    cout << i << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
