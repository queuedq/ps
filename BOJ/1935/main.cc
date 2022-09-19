#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, val[26];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S;
  for (int i=0; i<N; i++) cin >> val[i];
  
  vector<double> st;
  for (int i=0; i<sz(S); i++) {
    if ('A' <= S[i] && S[i] <= 'Z') {
      st.push_back(val[S[i] - 'A']);
    } else {
      double a, b;
      b = st.back(); st.pop_back();
      a = st.back(); st.pop_back();

      if (S[i] == '+') {
        st.push_back(a+b);
      } else if (S[i] == '-') {
        st.push_back(a-b);
      } else if (S[i] == '*') {
        st.push_back(a*b);
      } else if (S[i] == '/') {
        st.push_back(a/b);
      }
    }
  }

  cout << fixed << setprecision(2) << st.back() << endl;

  ////////////////////////////////
  return 0;
}
