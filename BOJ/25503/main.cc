#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, A[MN];
vector<pii> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) {
    st.push_back({A[i], A[i]});
    while (sz(st) >= 2) {
      auto [a, b] = st[sz(st)-1];
      auto [c, d] = st[sz(st)-2];
      if (b+1 == c || d+1 == a) {
        st.pop_back(); st.pop_back();
        st.push_back({min(a, c), max(b, d)});
      } else break;
    }
  }
  cout << (sz(st) == 1 ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
