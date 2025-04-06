#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
string S;

void solve() {
  cin >> S;
  N = sz(S);

  string T;
  int h = 0, cost = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == 'C') {
      if (h < N-i) h++, T.push_back('(');
      else h--, cost+=2, T.push_back(')');
    } else if (S[i] == 'U') {
      if (h > 0) h--, cost++, T.push_back(')');
      else h++, cost++, T.push_back('(');
    }
  }

  cout << cost << endl;
  cout << T << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
