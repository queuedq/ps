#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  int ans = 0;
  bool zero_one = false; // grundy 0 to 1
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    ans ^= a;
    if (a&1) zero_one = true;
  }

  cout << ((ans == 1 || ans == 0 && !zero_one) ? "Bob\n" : "Alice\n");

  ////////////////////////////////
  return 0;
}
