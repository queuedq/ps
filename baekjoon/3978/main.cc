#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, K;
string S;
set<string> sub;

bool iter(string &s, int len) {
  if (len == M) return sub.find(s) == sub.end();
  for (int i=0; i<K; i++) {
    s.push_back('a' + i);
    if (iter(s, len+1)) return true;
    s.pop_back();
  }
  return false;
}

void calc() {
  cin >> N >> M >> K >> S;
  for (int i=0; i<N-M+1; i++) {
    string s;
    for (int j=i; j<i+M; j++) s.push_back(S[j]);
    sub.insert(s);
  }

  string s;
  int len = 0;
  assert(iter(s, len));
  assert(s.size() == M);
  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    calc();
    sub.clear();
  }

  ////////////////////////////////
  return 0;
}
