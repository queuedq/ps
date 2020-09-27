#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct AST {
  char c;
  bool s;
  vector<AST*> nodes;

  AST(char c, bool s, vector<AST*> n): c(c), s(s), nodes(n) { }
};

void solve() {
  string M, S; cin >> M >> S;

  vector<AST*> st;
  for (int i=0; i<M.size(); i++) {
    if (M[i] == '|' || M[i] == ')') {
      vector<AST*> nodes;
      while (st.back()->c != '(' || st.back()->c != '|') {
        nodes.push_back(st.back());
        st.pop_back();
      }
      reverse(nodes.begin(), nodes.end());

      if (st.back()->c == '|') {
        delete st.back();
        st.pop_back();
      }
      st.push_back(new AST(0, true, nodes));
    }

    if (M[i] == ')') {
      vector<AST*> nodes;
      while (st.back()->c != '(') {
        nodes.push_back(st.back());
        st.pop_back();
      }

      delete st.back();
      st.pop_back();
      st.push_back(new AST(0, false, nodes));
    }

    if (M[i] != ')') {
      st.push_back(new AST(M[i], false, {}));
    }
  }


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
