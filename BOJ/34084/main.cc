#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
int N, T;
int state = 0; // currently xor-ed value

bool query(int a) {
  cout << "? " << (state ^ a) << endl;
  state = a;
  bool ans; cin >> ans;
  return ans;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  state = 0;
  int mask = (1<<N) - 1;

  // query bit pattern
  int ans = 0;
  for (int i=0; i<N; i++) {
    bool p = query(1<<i);
    if (p) ans |= 1 << i;
  }

  // find if answer should be flipped
  if (N%4 <= 1) {
    bool p = query(ans ^ 1);
    if (p == 0) answer(ans); // 1 ones after xor
    else answer(ans ^ mask); // 0, 3 mod 4 ones after xor

  } else {
    bool p = query(ans);
    if (p == 0) answer(ans); // 0 ones after xor
    else answer(ans ^ mask); // 2, 3 mod 4 ones after xor
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> T;

  // map (bit count) % 4 to...
  // N = 0, 1 mod 4 -> 1 0 0 1
  // N = 2, 3 mod 4 -> 0 0 1 1
  for (int x=0; x<1<<N; x++) {
    int cnt = 0;
    for (int i=0; i<N; i++) if (x>>i & 1) cnt++;
    if (N%4 <= 1) cout << (cnt%4 == 0 || cnt%4 == 3);
    else cout << (cnt%4 == 2 || cnt%4 == 3);
  }
  cout << endl;

  while (T--) solve();

  ////////////////////////////////
  return 0;
}
