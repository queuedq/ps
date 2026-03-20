#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  while (1) {
    string S;
    getline(cin, S);
    if (S == ".") break;

    stack<char> stk;
    bool ok = true;
    for (char c: S) {
      if (c == '(' || c == '[') stk.push(c);
      else if (c == ')') {
        if (stk.empty() || stk.top() != '(') { ok = false; break; }
        stk.pop();
      } else if (c == ']') {
        if (stk.empty() || stk.top() != '[') { ok = false; break; }
        stk.pop();
      }
    }

    if (!stk.empty()) ok = false;
    cout << (ok ? "yes" : "no") << endl;
  }

  ////////////////////////////////
  return 0;
}
