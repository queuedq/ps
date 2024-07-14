#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

lld solve() {
  int N;
  string S;
  cin >> N >> S;

  lld ans = 0, j = 1;
  for (int i=0; i<N; i++) {
    if ((S[i] == 'T') ^ (i & 1)) {
      ans += abs(i - j);
      j += 2;
    }
  }

  if (j-2 < N && N <= j) return ans;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
