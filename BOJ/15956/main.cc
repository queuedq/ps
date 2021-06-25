#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct disjoint_set {
  vector<int> p, s;

  disjoint_set(int sz) {
    p.resize(sz); s.resize(sz);
    for (int i = 0; i < sz; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
  }

  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return s[find(x)]; }
};

////////////////////////////////////////////////////////////////
string S;
vector<string> var;
unordered_map<string, int> varId;

struct Condition { bool eq; int v1, v2; };
vector<Condition> cond;

void parseCond(int i, int j) {
  int k;
  for (k=i; k<j; k++) {
    if (S[k] == '!' || S[k] == '=') break;
  }
  string v1 = S.substr(i, k-i);
  string v2 = S.substr(k+2, j-k-2);

  if (varId.count(v1) == 0) {
    varId[v1] = var.size();
    var.push_back(v1);
  }
  if (varId.count(v2) == 0) {
    varId[v2] = var.size();
    var.push_back(v2);
  }

  cond.push_back({S[k] == '=', varId[v1], varId[v2]});
}

void parse() {
  int i=0;
  for (int j=0; j<S.size(); j++) {
    if (S[j] == '&') {
      parseCond(i, j);
      i = j+2;
      j++;
    }
  }
  parseCond(i, S.size());
}

////////////////////////////////

const string TAUTOLOGY = "0==0";
const string CONTRADICTION = "0!=0";
bool isNum(string s) { return s[0] == '-' || ('0' <= s[0] && s[0] <= '9'); }

string solve() {
  disjoint_set D(var.size());
  vector<int> rep(var.size()), val(var.size());
  vector<Condition> ans;

  auto getRep = [&](int v) -> int& { return rep[D.find(v)]; };
  auto getVal = [&](int v) -> int& { return val[D.find(v)]; };

  // Construct equivalence groups and
  // find representitves (shortest variables) of each groups
  for (int i=0; i<rep.size(); i++) rep[i] = i;
  for (auto c: cond) {
    if (!c.eq) continue;
    int r1 = getRep(c.v1);
    int r2 = getRep(c.v2);
    int r = var[r1].size() < var[r2].size() ? r1 : r2;
    D.merge(c.v1, c.v2);
    getRep(c.v1) = r;
  }

  // Contradiction check 1
  // Check if two different numbers are in the same group and
  // assign values to each group
  fill(val.begin(), val.end(), -1); // No value assigned
  for (int i=0; i<var.size(); i++) {
    if (!isNum(var[i])) continue;
    if (getVal(i) != -1) return CONTRADICTION;
    getVal(i) = i;
  }

  // Contradiction check 2
  // Check if two variables in the same group are connected with not equal sign
  for (auto c: cond) {
    if (c.eq) continue;
    if (D.same(c.v1, c.v2)) return CONTRADICTION;
  }

  // Find equivalence conditions
  for (int i=0; i<var.size(); i++) {
    if (getRep(i) == i) continue;
    ans.push_back({true, i, getRep(i)});
  }

  // Find inequivalence conditions
  set<pii> ineq;
  for (auto c: cond) {
    if (c.eq) continue;
    if (getVal(c.v1) != -1 && getVal(c.v2) != -1) {
      assert(getVal(c.v1) != getVal(c.v2));
      continue;
    }
    int r1 = getRep(c.v1);
    int r2 = getRep(c.v2);
    if (r1 > r2) swap(r1, r2);
    ineq.insert({r1, r2});
  }

  for (auto [v1, v2]: ineq) {
    ans.push_back({false, v1, v2});
  }

  // Return
  if (ans.size() == 0) return TAUTOLOGY;

  string ansStr = "";
  for (int i=0; i<ans.size(); i++) {
    Condition c = ans[i];
    if (i > 0) ansStr.append("&&");
    ansStr.append(var[c.v1]);
    ansStr.append(c.eq ? "==" : "!=");
    ansStr.append(var[c.v2]);
  }

  return ansStr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> S;
  parse();
  cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
