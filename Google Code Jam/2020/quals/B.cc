#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

string calc() {
  string n; cin >> n;

  string s;
  int depth = 0;
  for (int i=0; i<n.size(); i++) {
    while (depth < n[i] - '0') { s.push_back('('); depth++; }
    while (depth > n[i] - '0') { s.push_back(')'); depth--; }
    s.push_back(n[i]);
  }
  while (depth > 0) { s.push_back(')'); depth--; }

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i=1; i<=T; i++) {
    cout << "Case #" << i << ": " << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
