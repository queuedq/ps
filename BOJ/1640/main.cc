#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, M, A[MN][MN], R[MN], C[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<M; j++) {
      A[i][j] = S[j] - '0';
      R[i] ^= A[i][j];
      C[j] ^= A[i][j];
    }
  }

  int a=0, b=0;
  for (int i=0; i<N; i++) a += R[i];
  for (int i=0; i<M; i++) b += C[i];
  // fun fact: a%2 = b%2 (= sum A[i][j] mod 2)

  lld ans = MN*2;
  if (a%2 == 0) ans = min(a+b, (N-a)+(M-b));
  else ans = min(a+(M-b), (N-a)+b);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
