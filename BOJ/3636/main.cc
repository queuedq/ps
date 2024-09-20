#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<vector<string>> clauses;
unordered_map<string, vector<int>> which_clauses; // which clauses contain this var as premise
vector<int> cnt; // remaining false premises
map<string, bool> value;

void parse(string &S) {
  int i = 0, j = 0;
  vector<string> cl;

  while (i < sz(S)) {
    i = S.find('(', i) + 1;

    while (1) {
      j = S.find_first_of("&=", i);
      string var = S.substr(i, j - i);
      if (!var.empty()) cl.push_back(var);

      if (S[j] == '&') i = j + 1; // skip '&'
      else { i = j + 2; break; } // skip "=>"
    }

    j = S.find(')', i);
    string con = S.substr(i, j - i);
    if (con.empty()) con = "$"; // this must remain false
    cl.push_back(con);
    i = j + 1; // skip ')'

    clauses.push_back(cl);
    cl.clear();
  }
}

void preprocess() {
  for (int n=0; n<sz(clauses); n++) {
    auto &cl = clauses[n];
    for (int i=0; i<sz(cl); i++) {
      auto &var = cl[i];
      if (i < sz(cl)-1) which_clauses[var].push_back(n);
      value[var] = 0;
    }
    cnt.push_back(sz(cl) - 1);
  }
  value["$"] = 0;
}

void reset() {
  clauses.clear();
  which_clauses.clear();
  cnt.clear();
  value.clear();
}

void solve(string &S) {
  parse(S);
  preprocess();

  queue<string> Q;
  for (int n=0; n<sz(clauses); n++) {
    auto &con = clauses[n].back();
    if (cnt[n] == 0 && !value[con]) {
      value[con] = 1;
      Q.push(con);
    }
  }

  while (!Q.empty()) {
    auto var = Q.front(); Q.pop();
    for (auto n: which_clauses[var]) {
      auto &con = clauses[n].back();
      if (--cnt[n] == 0 && !value[con]) {
        value[con] = 1;
        Q.push(con);
      }
    }
  }

  if (value["$"]) {
    cout << "unsatisfiable" << endl;
  } else {
    value.erase("$");
    for (auto it=value.begin(); it!=value.end(); it++) {
      auto [name, val] = *it;
      cout << name << "=" << (val ? "true" : "false");
      if (next(it) != value.end()) cout << ",";
    }
    cout << endl;
  }

  reset();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S;
  while (cin >> S) solve(S);

  ////////////////////////////////
  return 0;
}
