#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int var;

inline bool getValue(char v) {
  if (v == '0' || v == '1') return v - '0';
  return (var >> (v - 'a')) & 1;
}

struct AST {
  char a, b, v=0;
  AST *left, *right;

  AST(char v): v(v) { }
  AST(char a, char b, AST *left, AST *right): a(a), b(b), left(left), right(right) {}

  bool eval() {
    if (v != 0) return getValue(v);
    if (getValue(a) == getValue(b)) return left->eval();
    return right->eval();
  }
};

AST *parse(string expr) {
  // value
  if (expr.size() == 1) return new AST(expr[0]);

  // conditional
  char a = expr[0], b = expr[3];
  string left, right;
  int i=5, depth=1;
  for (; ; i++) {
    if (expr[i] == '?') depth++;
    else if (expr[i] == ':') depth--;
    if (depth == 0) break;
    left.push_back(expr[i]);
  }
  for (i++; i<expr.size(); i++) right.push_back(expr[i]);
  // cout << a << " " << b << " " << left << " " << right << endl;

  return new AST(a, b, parse(left), parse(right));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  string S; cin >> S;

  AST *expr = parse(S);

  int ans = 0;
  for (var=0; var<1<<N; var++) {
    // cout << expr->eval();
    ans += expr->eval() == 0;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
