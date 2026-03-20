#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string S;
vector<char> stk;
int priority[256];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  priority['+'] = 1; priority['-'] = 1;
  priority['*'] = 2; priority['/'] = 2;

  cin >> S;
  S = "(" + S + ")";

  for (auto c: S) {
    if ('A' <= c && c <= 'Z') {
      cout << c;

    } else if (c == '(') {
      stk.push_back(c);

    } else if (c == ')') {
      while (!stk.empty() && stk.back() != '(') {
        char op = stk.back(); stk.pop_back();
        cout << op;
      }
      if (!stk.empty()) stk.pop_back();

    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!stk.empty() && stk.back() != '(' && priority[(int)stk.back()] >= priority[(int)c]) {
        char op = stk.back(); stk.pop_back();
        cout << op;
      }
      stk.push_back(c);
      
    } else {
      assert(0);
    }
  }

  cout << endl;

  ////////////////////////////////
  return 0;
}
