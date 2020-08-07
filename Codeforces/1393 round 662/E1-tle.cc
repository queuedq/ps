#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
const int MAXN = 1005;
lld N;
vector<lld> D[MAXN]; // D[x][A[x].size()]: No removal
string A[MAXN];

bool cmp(const string &a, const string &b, int x, int y) { // remove a[x], b[y]
  int i=0, j=0;
  if (x == 0) i++;
  if (y == 0) j++;
  for (; i<a.size() && j<b.size(); i++, j++) {
    if (a[i] > b[j]) return false;
    if (a[i] < b[j]) return true;
    if (i+1 == x) i++;
    if (j+1 == y) j++;
  }
  if (i < a.size()) return false;
  if (j < b.size()) return true;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  for (int i=0; i<=A[0].size(); i++) D[0].push_back(1);

  for (int i=1; i<N; i++) {
    D[i].resize(A[i].size() + 1);

    for (int x=0; x<=A[i-1].size(); x++) {
      for (int y=0; y<=A[i].size(); y++) {
        if (cmp(A[i-1], A[i], x, y)) {
          D[i][y] = (D[i][y] + D[i-1][x]) % MOD;
        }
      }
    }
  }

  int ans = 0;
  for (int x=0; x<=A[N-1].size(); x++) {
    ans = (ans + D[N-1][x]) % MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
