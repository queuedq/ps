#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int N = 44;
lld F[N];
lld M, A[N][N];
vector<pii> digits; // (k, cnt), value = F[k] * cnt

void decomp(int n) {
  if (n == 0) return;

  // edge cases
  assert(n != 1);
  if (n == 4) { digits.push_back({2, 2}); return; }
  if (n == 6) { digits.push_back({3, 2}); return; }

  // find largest fib
  int k = 0;
  for (;; k++) if (F[k+1] > n) break;

  // recurse
  if (n == F[k]+1) { // edge case
    digits.push_back({k-1, 1});
    decomp(n - F[k-1]);
  } else {
    digits.push_back({k, 1});
    decomp(n - F[k]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  F[0] = F[1] = 1;
  for (int i=2; i<N; i++) F[i] = F[i-1] + F[i-2];
  // (F[41] = 267,914,296) <= max M < (F[42] = 433,494,437)

  cin >> M;

  // edge cases
  if (M == 1) {
    cout << 2 << endl;
    cout << ".." << endl;
    cout << "#." << endl;
    return 0;
  }
  if (M == 2) {
    cout << 3 << endl;
    cout << "..." << endl;
    cout << "##." << endl;
    cout << "##." << endl;
    return 0;
  }

  if (M % 2) M *= 2; // make even number
  decomp(M / 2);

  // draw borders
  for (int i=0; i<N-2; i++) A[0][i] = A[i][0] = 1;
  for (int i=2; i<N; i++) A[N-1][i] = A[i][N-1] = 1;

  // draw diagonals
  bool left = 1;
  for (auto [k, cnt]: digits) {
    for (int i=k, j=2; i<N-2; i++, j++) (left ? A[i][j] : A[j][i]) = 1;
    for (int i=k, j=1; i<N-1; i++, j++) (left ? A[i][j] : A[j][i]) = 1;

    if (cnt == 2) { // bend once more
      if (left) A[k+1][3] = 0, A[k+2][2] = 1;
      else A[(N-1)-(k+1)][(N-1)-3] = 0, A[(N-1)-(k+2)][(N-1)-2] = 1;
    }

    left ^= 1;
  }

  // print
  cout << N << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cout << (A[i][j] ? '.' : '#');
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
