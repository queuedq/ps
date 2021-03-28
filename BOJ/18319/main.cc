#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, K, B[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> B[i];

  int ans = 0;
  for (int b=1; b<=1000; b++) {
    int full = 0;
    priority_queue<int> R;

    for (int i=0; i<N; i++) {
      full += B[i] / b;
      R.push(B[i] % b);
    }

    if (full < K/2) break;
    full -= K/2;

    int score = 0, j = 0;
    for (int i=0; i<K/2; i++) {
      if (full > 0) {
        score += b;
        full--;
      } else {
        if (R.empty()) break;
        score += R.top();
        R.pop();
      }
    }

    ans = max(ans, score);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
