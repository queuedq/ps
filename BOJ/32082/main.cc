#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int gcd_moves(int a, int b) { // how many moves (a -= b) to reach 0
  int cnt = 0;
  while (a && b) {
    cnt += a / b;
    a %= b;
    swap(a, b);
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N; cin >> N;
  
  lld moves = 0;
  for (int i=0; i<N; i++) {
    int r, c; cin >> r >> c;
    moves += gcd_moves(r, c);
    moves += gcd_moves(r-1, c);
    moves += gcd_moves(r, c-1);
    moves += gcd_moves(r-1, c-1);
  }

  if (moves % 2 == 0) cout << "SECOND" << endl;
  else cout << "FIRST" << endl;

  ////////////////////////////////
  return 0;
}
