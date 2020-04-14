#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, A[MAXN];
priority_queue<int> D;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  lld ans = 0;
  for (int i=0; i<N; i++) {
    D.push(A[i]-i);
    D.push(A[i]-i);
    ans += D.top() - (A[i]-i);
    D.pop();
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
