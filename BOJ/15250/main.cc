#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
int N;
string S;

int calc() {
  cin >> S;
  N = S.size();

  lld lhash = 0, rhash = 0, pow = 1;
  int l = 0, cnt = 0;
  for (int i=0; i<N/2; i++) {
    lhash = (lhash*26 + S[i]-'a') % MOD;
    rhash = (rhash + pow*(S[N-i-1]-'a')) % MOD;
    pow = pow*26 % MOD;

    if (lhash == rhash) {
      cnt += 2;
      lhash = rhash = 0;
      pow = 1;
      l = i+1;
    }
  }
  if (l*2 != N) cnt++;

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
