#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int N, K, A[MN], C[MN];

void solve(int N, int K) {
  while (true) {
    for (int i=1; i<=N; i++) cin >> A[i];

    for (int i=1; i<=N; i++) {
      int j=i;
      do {
        C[j] = i;
        j = A[j];
      } while (j != i);
    }
    
    for (int i=1; i<=N; i++) cout << C[i] << " ";
    cout << endl;
    bool ok; cin >> ok;
    if (ok) return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T >> N >> K;
  for (int t=1; t<=T; t++) {
    solve(N, K);
  }

  ////////////////////////////////
  return 0;
}
