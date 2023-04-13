#include <bits/stdc++.h>
using namespace std;

// triangle edges (a, b, a+b)
// 1, 11, 12
// 3, 7, 10
// 4, 5, 9
// 2, 6, 8
vector<array<int, 3>> ans;

int main() {
  int N = 25;
  for (int i=0; i<N; i++) {
    ans.push_back({i, i+1, i+12});
    ans.push_back({i, i+3, i+10});
    ans.push_back({i, i+4, i+9});
    ans.push_back({i, i+2, i+8});
  }
  for (auto [a, b, c]: ans) {
    a %= N, b %= N, c %= N;
    cout << (char)('A'+a) << (char)('A'+b) << (char)('A'+c) << "\n";
  }
  return 0;
}
