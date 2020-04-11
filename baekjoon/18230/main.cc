#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2005;
int N, A, B, T1[MAXN], T2[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> A >> B;
  for (int i=0; i<A; i++) cin >> T1[i];
  for (int i=0; i<B; i++) cin >> T2[i];

  sort(T1, T1+A, greater<int>());
  sort(T2, T2+B, greater<int>());

  vector<int> squares;
  for (int i=0; i<B; i++) squares.push_back(T2[i]);
  for (int i = N%2; i+1 < A; i+=2) {
    squares.push_back(T1[i] + T1[i+1]);
  }

  sort(squares.rbegin(), squares.rend());

  int ans = N%2 ? T1[0] : 0;
  for (int i=0; i<N/2; i++) {
    ans += squares[i];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
