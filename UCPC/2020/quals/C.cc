#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, var[28];

inline bool isBool(char a) { return a == '0' || a == '1'; }
inline int boolToVar(char a) { return a - '0' + 'a' + 26; }

struct AST {
  char a, b, v=0;
  AST *left, *right;

  AST(char v): v(v) { }
  AST(char a, char b, AST *left, AST *right): a(a), b(b), left(left), right(right) {}

  int eval(int used) {
    if (v != 0) {
      if (var[v-'a'] == 0) return 1 << N-used;
      if (var[v-'a'] == 1) return 0;
      return 1 << N-used-1;
    }

    int res = 0;
    int &x = var[a-'a'];
    int &y = var[b-'a'];

    if (x == 2 && y == 2) {
      int d = a==b ? 1 : 2;
      for (x=0; x<2; x++) for (y=0; y<2; y++) {
        if (x == y) res += left->eval(used+d);
        else res += right->eval(used+d);
      }
      x = y = 2;
    } else if (x == 2) {
      for (x=0; x<2; x++) {
        if (x == y) res += left->eval(used+1);
        else res += right->eval(used+1);
      }
      x = 2;
    } else if (y == 2) {
      for (y=0; y<2; y++) {
        if (x == y) res += left->eval(used+1);
        else res += right->eval(used+1);
      }
      y = 2;
    } else {
      if (x == y) res += left->eval(used);
      else res += right->eval(used);
    }

    return res;
  }
};

AST *parse(string expr) {
  // value
  if (expr.size() == 1) {
    if (isBool(expr[0])) return new AST(boolToVar(expr[0]));
    return new AST(expr[0]);
  }

  // conditional
  char a = isBool(expr[0]) ? boolToVar(expr[0]) : expr[0];
  char b = isBool(expr[3]) ? boolToVar(expr[3]) : expr[3];
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

  cin >> N;
  string S; cin >> S;

  for (int i=0; i<N; i++) var[i] = 2;
  var[26] = 0;
  var[27] = 1;

  AST *expr = parse(S);
  cout << expr->eval(0) << endl;

  ////////////////////////////////
  return 0;
}
