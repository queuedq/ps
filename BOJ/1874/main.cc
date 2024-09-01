#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  vector<int> S;
  vector<char> ans;
  int x = 1, i = 1;
  while (i <= N) {
    if (!S.empty() && S.back() == A[i]) {
      ans.push_back('-');
      S.pop_back();
      i++;
    } else if (x <= N) {
      ans.push_back('+');
      S.push_back(x);
      x++;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  for (auto c: ans) cout << c << endl;

  ////////////////////////////////
  return 0;
}
