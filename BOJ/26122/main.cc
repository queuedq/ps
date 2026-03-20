#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N; string S;
vector<int> cnt;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S;
  
  cnt.push_back(1);
  for (int i=1; i<N; i++) {
    if (S[i-1] == S[i]) cnt.back()++;
    else cnt.push_back(1);
  }

  int ans = 0;
  for (int i=1; i<sz(cnt); i++) {
    ans = max(ans, min(cnt[i-1], cnt[i]) * 2);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
