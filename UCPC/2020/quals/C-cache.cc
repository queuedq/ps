#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))

////////////////////////////////////////////////////////////////
int var = 0;

inline bool isVar(char v) { return v != '0' && v != '1'; }

inline bool getVal(char v) {
  if (isVar(v)) return (var >> (v-'a')) & 1;
  return v - '0';
}

struct AST {
  char a, b, v=0;
  AST *left, *right;
  bool invalid[26], cache;

  AST(char v): v(v) {
    if (isVar(v)) invalid[v-'a'] = true;
  }

  AST(char a, char b, AST *left, AST *right): a(a), b(b), left(left), right(right) {
    for (int i=0; i<26; i++) {
      if (left->invalid[i]) invalid[i] = true;
      if (right->invalid[i]) invalid[i] = true;
    }
    if (isVar(a)) invalid[a-'a'] = true;
    if (isVar(b)) invalid[b-'a'] = true;
  }

  bool eval(int upd) {
    if (upd != -1 && !invalid[upd]) return cache;

    if (v != 0) return cache = getVal(v);
    left->eval(upd);
    right->eval(upd);
    if (getVal(a) == getVal(b)) return cache = left->cache;
    return cache = right->cache;
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
  return new AST(a, b, parse(left), parse(right));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  string S; cin >> S;

  AST *expr = parse(S);
  expr->eval(-1);

  int ans = 0, prev = 1<<(N-1);
  for (int i=0; i<1<<N; i++) {
    var = i ^ (i>>1); // gray code
    int upd = LOG2(prev ^ var);
    prev = var;

    // bool res = expr->eval(upd);
    // cout << bitset<8>(var) << " " << upd << " " << res << endl;

    ans += expr->eval(upd) == 0;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
