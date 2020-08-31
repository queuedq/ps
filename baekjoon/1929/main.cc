#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
bool prime[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime+2, prime+MAXN, true);

  for (int i=2; i*i<MAXN; i++) {
    if (!prime[i]) continue;
    for (int j=i*2; j<MAXN; j+=i) {
      prime[j] = false;
    }
  }

  int M, N; cin >> M >> N;
  for (int i=M; i<=N; i++) {
    if (prime[i]) cout << i << endl;
  }

  ////////////////////////////////
  return 0;
}
