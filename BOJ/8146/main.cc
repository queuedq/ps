#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
int N, A[MN*2], first[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N*2; i++) {
    cin >> A[i];
    if (!first[A[i]]) first[A[i]] = i;
  }

  vector<int> S, ans;

  for (int i=1; i<=N*2; i++) {
    if (first[A[i]] == i) {
      S.push_back(A[i]);
      continue;
    }

    int j = sz(S) - 1;
    while (S[j] != A[i]) {
      ans.push_back(j+1);
      j--;
    }
    S.erase(S.begin() + j);
  }

  cout << sz(ans) << endl;
  for (auto x: ans) cout << x << endl;

  ////////////////////////////////
  return 0;
}
