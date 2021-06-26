#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, D[101010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  D[0] = 0;
  for (int i=1; i<=N; i++) {
    D[i] = i;
    for (int j=1; j*j<=i; j++) {
      D[i] = min(D[i], D[i-j*j] + 1);
    }
  }
  
  cout << D[N];

  ////////////////////////////////
  return 0;
}
