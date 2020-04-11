#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
int N, K, S[MAXN];

int idx[26];
char alpha[21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  idx['a'-'a'] = -1;
  idx['n'-'a'] = -1;
  idx['t'-'a'] = -1;
  idx['i'-'a'] = -1;
  idx['c'-'a'] = -1;

  int j = 0;
  for (int i=0; i<26; i++) {
    if (idx[i] != -1) {
      idx[i] = j;
      alpha[j++] = i+'a';
    }
  }

  cin >> N >> K;
  K -= 5;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<s.size(); j++) {
      if (idx[s[j]-'a'] != -1) {
        S[i] = S[i] | (1 << idx[s[j]-'a']);
      }
    }
  }

  int ans = 0;
  for (int i=0; i<(1<<21); i++) {
    int cnt = 0;
    for (int m=1; m<=i; m <<= 1) {
      if (i & m) cnt++;
    }
    if (cnt != K) continue;

    int learnable = 0;
    for (int j=0; j<N; j++) {
      if ((i & S[j]) == S[j]) learnable++;
    }

    ans = max(ans, learnable);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
