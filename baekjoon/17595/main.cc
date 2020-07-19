#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
string S;
int N, L[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> S; N = S.size();

  int idx[26];
  fill(idx, idx+26, -1);
  for (int i=0; i<N; i++) {
    L[i] = idx[S[i]-'a'];
    idx[S[i]-'a'] = i;
  }

  fill(idx, idx+26, -1);
  int ans = 0;
  for (int i=0; i<S.size(); i++) {
    for (int c=0; c<26; c++) {
      if (idx[c] > L[i]) ans++;
    }
    idx[S[i]-'a'] = i;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
