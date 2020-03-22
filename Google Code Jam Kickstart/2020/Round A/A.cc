#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, B, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N >> B;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);

    int cost = 0, i = 0;
    for (; i<N; i++) {
      cost += A[i];
      if (cost > B) break;
    }
    cout << "Case #" << t << ": " << i << endl;
  }

  ////////////////////////////////
  return 0;
}
