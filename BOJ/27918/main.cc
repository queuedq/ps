#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, X, Y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    char c; cin >> c;
    if (c == 'D') X++;
    else Y++;
    if (abs(X - Y) >= 2) break;
  }
  cout << X << ":" << Y << endl;

  ////////////////////////////////
  return 0;
}
