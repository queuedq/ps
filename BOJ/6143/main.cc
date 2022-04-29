#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 30303;
int N; char S[MN];

bool cmp(int i, int j) {
  while (i < j) {
    if (S[i] == S[j]) { i++; j--; }
    else return S[i] < S[j];
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> S[i];
  
  int i=0, j=N-1;
  string ans;
  while (i <= j) {
    if (cmp(i, j)) ans.push_back(S[i++]);
    else ans.push_back(S[j--]);
  }

  for (int i=0; i<ans.size(); i++) {
    cout << ans[i];
    if ((i+1) % 80 == 0) cout << '\n';
  }

  ////////////////////////////////
  return 0;
}
