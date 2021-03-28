#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
bool cmp(string a, string b) {
  return a+b < b+a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int K, N; cin >> K >> N;
  vector<string> S(K);
  int sz = 0;
  for (int i=0; i<K; i++) {
    cin >> S[i];
    sz = max(sz, (int)S[i].size());
  }

  sort(S.begin(), S.end(), cmp);

  for (int i=N-1; i>=0; i--) {
    if (S[i].size() == sz) {
      for (int j=K; j<N; j++) S.push_back(S[i]);
      break;
    }
  }

  sort(S.begin(), S.end(), cmp);

  string ans = "";
  for (int i=N-1; i>=0; i--) ans.append(S[i]);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
