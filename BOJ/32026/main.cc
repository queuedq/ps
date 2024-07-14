#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Edge { int u, v, w; };
int W = 0;
vector<Edge> A, B;

int solve(int K) {
  if (K == 2) {
    B.push_back({1, 3, ++W});
    B.push_back({4, 1, ++W});
    B.push_back({2, 4, ++W});
    A.push_back({3, 4, ++W});
    A.push_back({2, 3, ++W});
    A.push_back({1, 2, ++W});
    return 4;
  }
  if (K == 3) {
    A.push_back({3, 4, ++W});
    B.push_back({2, 4, ++W});
    B.push_back({2, 3, ++W});
    B.push_back({1, 4, ++W});
    A.push_back({1, 3, ++W});
    A.push_back({1, 2, ++W});
    return 4;
  }

  int N = solve(K-1);
  for (int i=1; i<=N-1; i++) {
    A.push_back({i, N+i, ++W});
    B.push_back({N+i, i+1, ++W});
  }
  return N*2 - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int K; cin >> K;
  int N = solve(K);
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  cout << N << endl;
  for (auto [u, v, w]: A) cout << u << " " << v << " " << (W-w+1) << endl;
  for (auto [u, v, w]: B) cout << u << " " << v << " " << (W-w+1) << endl;

  ////////////////////////////////
  return 0;
}
