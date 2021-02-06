#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;
  int ans = 0;
  bool first = true;

  for (int i=0; i<N; i++) {
    float x; cin >> x;
    if (x != 0 && first) {
      ans += ceil(x);
      first = false;
    } else {
      ans += floor(x);
    }
  }

  cout << ans << endl;

  return 0;
}
