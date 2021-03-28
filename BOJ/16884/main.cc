#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    cout << (N % 2 ? "koosaga" : "cubelover") << "\n";
  }
  return 0;
}
