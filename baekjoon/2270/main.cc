#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const lld MOD = 1e6;
int N, pole[MAXN], pw[MAXN];

lld solve(int n, int to) {
  if (n == 0) return 0;
  if (pole[n] == to) return solve(n-1, to);
  return (solve(n-1, pole[n]^to) + pw[n-1]) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  pw[0] = 1;
  for (int i=1; i<=N; i++) { pw[i] = pw[i-1]*2 % MOD; }

  int a, b, c; cin >> a >> b >> c;
  for (int i=0; i<a; i++) {
    int x; cin >> x;
    pole[x] = 1;
  }
  for (int i=0; i<b; i++) {
    int x; cin >> x;
    pole[x] = 2;
  }
  for (int i=0; i<c; i++) {
    int x; cin >> x;
    pole[x] = 3;
  }

  cout << pole[N] << endl;
  cout << solve(N, pole[N]) << endl;

  ////////////////////////////////
  return 0;
}
