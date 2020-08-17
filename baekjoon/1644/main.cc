#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 4e6+5;
int N;
bool prime[MAXN];
vector<int> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  fill(prime, prime+N+1, true);
  for (int i=2; i*i<=N; i++) {
    if (!prime[i]) continue;
    for (int j = i*2; j <= N; j += i) prime[j] = false;
  }

  for (int i=2; i<=N; i++) {
    if (prime[i]) P.push_back(i);
  }

  int i = 0, sum = 0, ans = 0;
  for (int j=0; j<P.size(); j++) {
    sum += P[j];
    while (sum > N) {
      sum -= P[i];
      i++;
    }
    if (sum == N) ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
