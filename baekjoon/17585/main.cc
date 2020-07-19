#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<char> parseLine() {
  vector<char> ret;
  string line; getline(cin, line);

  istringstream iss(line); char c;
  while(iss >> c) ret.push_back(c);
  return ret;
}

int N;
bool var[26];
stack<bool> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string b; cin >> b;
    var[i] = b == "T";
  }

  cin.ignore();

  vector<char> circuit = parseLine();
  for (auto c: circuit) {
    if (c == '*') {
      bool x = S.top(); S.pop();
      bool y = S.top(); S.pop();
      S.push(x & y);
    } else if (c == '+') {
      bool x = S.top(); S.pop();
      bool y = S.top(); S.pop();
      S.push(x | y);
    } else if (c == '-') {
      bool x = S.top(); S.pop();
      S.push(!x);
    } else {
      S.push(var[c-'A']);
    }
  }

  cout << (S.top() ? 'T' : 'F') << endl;

  ////////////////////////////////
  return 0;
}
