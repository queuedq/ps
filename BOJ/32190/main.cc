#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void print(int x) { cout << x << " "; }

void solve(int N) {
  if (N == 0) return;
  if (N == 1) return print(1), print(1);

  print(N-1), print(N), print(N-1);
  solve(N-2);
  print(N);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N; cin >> N;
  solve(N);
  cout << endl;

  ////////////////////////////////
  return 0;
}
