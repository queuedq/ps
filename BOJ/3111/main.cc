#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
string S, T;
vector<char> s1, s2;

bool match(vector<char> &s, bool rev) {
  int sz = s.size();
  if (sz < M) return 0;
  if (!rev) {
    for (int i=0; i<M; i++)
      if (s[sz-M+i] != T[i]) return 0;
  } else {
    for (int i=0; i<M; i++)
      if (s[sz-i-1] != T[i]) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T >> S;
  N = S.size(), M = T.size();

  int i=0, j=S.size()-1;
  while (i<=j) {
    while (i<=j) {
      s1.push_back(S[i++]);
      if (match(s1, 0)) {
        s1.resize(s1.size() - M);
        break;
      }
    }
    while (i<=j) {
      s2.push_back(S[j--]);
      if (match(s2, 1)) {
        s2.resize(s2.size() - M);
        break;
      }
    }
  }

  for (int j=(int)s2.size()-1; j>=0; j--) {
    s1.push_back(s2.back()); s2.pop_back();
    if (match(s1, 0)) s1.resize(s1.size() - M);
  }

  cout << string(s1.begin(), s1.end()) << endl;

  ////////////////////////////////
  return 0;
}
