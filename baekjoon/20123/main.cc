#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<string> tri6 = {
  "|",
  "b-",
  "p-|",
  "||b-",
  "|b-||",
  "b--db-",
};
vector<string> tri9 = {
  "|",
  "b-",
  "p-|",
  "|-d|",
  "p-|b-",
  "|-d-q|",
  "p-p-|b-",
  "||||p-||",
  "-d-d|-db-",
};
vector<string> rect = {
  "p-",
  "||",
  "-d",
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int n; cin >> n;
  vector<string> ans(n);
  for (int i=0; i<n; i++) {
    ans[i] = string(i+1, '*');
  }

  if (n < 6) {
    if (n == 2) ans = {"|", "b-"};
  } else if (n%6 == 0 || n%6 == 2) {
    int m = n - n%3;
    int r = n%3;

    for (int i=0; i<m; i++) {
      for (int j=0; j<=i; j++) {
        if (j >= i/6*6) ans[i+r][j] = tri6[i%6][j%6];
        else ans[i+r][j] = rect[i%3][j%2];
      }
    }
  } else if (n%6 == 3 || n%6 == 5) {
    int m = n - n%3;
    int r = n%3;

    for (int i=0; i<m-9; i++) {
      for (int j=0; j<=i; j++) {
        if (j >= i/6*6) ans[i+r][j] = tri6[i%6][j%6];
        else ans[i+r][j] = rect[i%3][j%2];
      }
    }

    for (int i=m-9; i<m; i++) {
      for (int j=0; j<=i; j++) {
        if (j >= m-9) ans[i+r][j] = tri9[i-m+9][j-m+9];
        else ans[i+r][j] = rect[i%3][j%2];
      }
    }
  }

  if (n >= 6 && n%3 == 2) {
    for (int i=0; i<n; i+=3) {
      ans[i][i] = '|';
      ans[i+1][i] = 'b';
      ans[i+1][i+1] = '-';
    }
    for (int i=0; i<n-3; i+=3) {
      ans[i+2][i+1] = '-';
      ans[i+2][i+2] = 'q';
      ans[i+3][i+2] = '|';
    }
  }

  if (ans[0] == "*") {
    cout << "impossible" << endl;
  } else {
    for (auto s: ans) cout << s << endl;
  }

  ////////////////////////////////
  return 0;
}
