#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, cnt;
vector<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    while (st.size() > 0 && st.back() > y) st.pop_back();
    if (st.size() > 0 && st.back() == y) continue;
    if (y > 0) {
      st.push_back(y);
      cnt++;
    }
  }
  
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
