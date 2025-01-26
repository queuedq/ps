#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, K, A[MN];

int greedy(int mask) {
  int cnt = 0, cur = 0;
  for (int i=0; i<N; i++) {
    cur |= A[i] & mask;
    if (cur == mask) cnt++, cur = 0;
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];

  int mask = 0;
  for (int b=30; b>=0; b--) {
    int cnt = greedy(mask | 1<<b);
    if (cnt >= N-K) mask |= 1<<b;
  }

  cout << mask << endl;

  ////////////////////////////////
  return 0;
}
