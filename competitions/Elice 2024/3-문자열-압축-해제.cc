#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int main() {
  string S; cin >> S;
  int N = S.size();
  vector<lld> stk;
  for (int i=0; i<N; i++) {
    if ('0' <= S[i] && S[i] <= '9') {
      if (i+1 < N && S[i+1] == '(') stk.push_back(S[i]-'0');
      else stk.push_back(1);
    } else if (S[i] == '(') {
      stk.push_back(-1);
    } else if (S[i] == ')') {
      lld sum = 0;
      while (stk.back() != -1) {
        sum += stk.back(); stk.pop_back();
      }
      stk.pop_back();
      stk.back() *= sum;
    }
  }

  lld sum = 0;
  for (auto x: stk) sum += x;
  cout << sum << endl;
  return 0;
}
