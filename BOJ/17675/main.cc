#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, A[MN], B[MN], D[MN][3][2]; // off(1)/on(2), xor

int get_bit(int x, int a, int b) {
  if (a == 0) return x^b;
  return (a-1)^b;
}

int get_cost(int a, int b, int c, int d) { // +1 at falling edge
  int res = 0;
  if (a && a != c) res++;
  if (b && !d) res++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { char c; cin >> c; A[i] = c-'0'; }
  for (int i=1; i<=N; i++) { char c; cin >> c; B[i] = c-'0'; }

  for (int i=1; i<=N; i++)
    for (auto a: {0, 1, 2})
      for (auto b: {0, 1})
        D[i][a][b] = MN;

  for (int i=1; i<=N; i++) {
    for (auto a: {0, 1, 2}) {
      for (auto b: {0, 1}) {
        if (get_bit(A[i], a, b) != B[i]) continue;

        for (auto c: {0, 1, 2}) {
          for (auto d: {0, 1}) {
            D[i][c][d] = min(D[i][c][d], D[i-1][a][b] + get_cost(a, b, c, d));
          }
        }
      }
    }
  }

  cout << D[N][0][0] << endl;

  ////////////////////////////////
  return 0;
}
