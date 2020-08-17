#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, D[1'000'005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=2; i<=N; i++) {
    D[i] = D[i-1]+1;
    if (i%2 == 0) D[i] = min(D[i], D[i/2]+1);
    if (i%3 == 0) D[i] = min(D[i], D[i/3]+1);
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
