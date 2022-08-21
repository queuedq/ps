#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int num = 0, ans = 0, neg = 0;
  for (int i=0; i<=S.size(); i++) {
    if ('0' <= S[i] && S[i] <= '9') num = num*10 + (S[i]-'0');
    else {
      if (!neg) ans += num;
      else ans -= num;
      num = 0;
      if (S[i] == '-') neg = 1;
    }
  }
  if (!neg) ans += num;
  else ans -= num;
  cout << ans << endl;
  return 0;
}
