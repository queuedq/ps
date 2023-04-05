#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int X, Y;
string S;

int cost(string &S) {
  int ret = 0;
  for (int i=1; i<S.size(); i++) {
    if (S[i-1] == 'C' && S[i] == 'J') ret += X;
    if (S[i-1] == 'J' && S[i] == 'C') ret += Y;

    if ((S[i-1] == '?' && S[i] == 'J') || (S[i-1] == 'C' && S[i] == '?')) {
      ret += min(0, X);
    }
    if ((S[i-1] == '?' && S[i] == 'C') || (S[i-1] == 'J' && S[i] == '?')) {
      ret += min(0, Y);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> X >> Y >> S;

    for (int i=1; i<S.size()-1; i++) {
      if (S[i] != '?' || S[i-1] == '?') continue;
      if (X+Y >= 0) S[i] = S[i-1];
      else S[i] = 'C' + 'J' - S[i-1];
    }

    for (int i=S.size()-2; i>=1; i--) {
      if (S[i] != '?' || S[i+1] == '?') continue;
      if (X+Y >= 0) S[i] = S[i+1];
      else S[i] = 'C' + 'J' - S[i+1];
    }

    printf("Case #%d: %d\n", t, cost(S));
  }

  ////////////////////////////////
  return 0;
}
