#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  cout << (N % 2 == 0 || M % 2 == 0 ? "A" : "B") << endl;
  return 0;
}
