#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
bool cmp(string a, string b) {
  int as = a.size(), bs = b.size(), s = as*bs;
  for (int i=0; i<s; i++) {
    if (a[i % as] < b[i % bs]) return true;
    if (a[i % as] > b[i % bs]) return false;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  vector<string> S(N);
  for (int i=0; i<N; i++) cin >> S[i];

  sort(S.begin(), S.end(), cmp);

  string ans = "";
  for (int i=0; i<N; i++) ans.append(S[i]);

  for (int i=1; i<N; i++) {
    string tmp = S[i];
    for (int j=0; j<N; j++) {
      if (j != i) tmp.append(S[j]);
    }
    if (tmp[0] == '0') continue;
    if (ans[0] == '0' || tmp < ans) ans = tmp;
  }

  if (ans[0] == '0') cout << "INVALID" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
