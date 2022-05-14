#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M, K, b[MN], s[MN], vst[MN];
set<int> bi[MN], si[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=M; i++) { int _; cin >> _ >> _; }
  for (int i=1; i<=N; i++) {
    cin >> b[i];
    bi[b[i]].insert(i);
  }
  for (int i=1; i<=N; i++) {
    cin >> s[i];
    si[s[i]].insert(i);
  }

  vector<int> st;
  for (int c=1; c<=N; c++) st.push_back(c);
  while (!st.empty()) {
    int c = st.back(); st.pop_back();
    if (vst[c]) continue;

    int uniq = 0;
    for (auto i: si[c]) {
      if (bi[b[i]].size() == 1) { uniq = b[i]; break; }
    }
    
    if (uniq) {
      vst[c] = 1;
      for (auto i: si[c]) {
        bi[b[i]].erase(i);
        if (bi[b[i]].size() == 1) st.push_back(s[*bi[b[i]].begin()]);
        b[i] = uniq;
      }
    }
  }

  cout << "TAK" << endl;
  for (int i=1; i<=N; i++) cout << b[i] << " \n"[i==N];

  ////////////////////////////////
  return 0;
}
