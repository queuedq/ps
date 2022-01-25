#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    int N, cnt = 0; cin >> N;
    for (int i=0; i<N; i++) {
      int d; cin >> d;
      cnt += d > 1;
    }

    if (N == 2)
      cout << 1 << '\n';
    else
      cout << min(N/2, cnt) << '\n';
  }

  ////////////////////////////////
  return 0;
}
