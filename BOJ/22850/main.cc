#include <bits/stdc++.h>
using namespace std;

bool win(int n) {
  if (n == 1 || n == 2 || n == 16 || n == 36) return 0;
  for (int x: {6, 10, 22, 26, 30}) {
    if (n % 34 == x) return 0;
  }
  return 1;
}

int main() {
  int N, M; cin >> N >> M;
  if (win(N) || win(M)) cout << "sh" << endl;
  else cout << "hs" << endl;
}
