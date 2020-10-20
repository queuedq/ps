#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

string nextstr(string S) {
  string T = S;
  for (int i=T.size()-1; i>=0; i--) {
    if (T[i] < 'z') { T[i]++; break; }
    T[i] = 'a';
  }
  return T;
}

string solve(const string &S) {
  int n = S.size();
  if (n == 1) return S;

  string L = S.substr(0, n/2);
  string R = S.substr(n-n/2, n/2);

  if (n % 2 == 0) {
    string H = solve(L);
    if (H == L && H < R) H = solve(nextstr(H));
    return H + H;
  } else {
    char c = S[n/2];
    string H = solve(L);
    if (H > L) {
      return H + 'a' + H;
    } else if (H >= R) {
      return H + c + H;
    } else if (c < 'z') {
      return H + char(c+1) + H;
    } else {
      H = solve(nextstr(H));
      return H + 'a' + H;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string S; cin >> S;
  cout << solve(S) << endl;

  ////////////////////////////////
  return 0;
}
