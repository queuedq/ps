#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, N, prime[3000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime+2, prime+3000, 1);
  for (int p=2; p<3000; p++) {
    if (!prime[p]) continue;
    for (int m=p*2; m<3000; m+=p) prime[m] = false;
  }

  cin >> K >> N;
  int cnt = 0;
  for (int i=2000; i<3000; i++) {
    if (prime[i]) {
      for (int j=1; j<=N; j++) cout << (lld)i*j << " ";
      cout << endl;
      cnt++;
    }
    if (cnt == K) break;
  }

  ////////////////////////////////
  return 0;
}
