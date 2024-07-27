#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S = to_string(N);
  sort(S.begin(), S.end());
  for (int i=N+1; i<=999999; i++) {
    string T = to_string(i);
    sort(T.begin(), T.end());
    if (S == T) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
