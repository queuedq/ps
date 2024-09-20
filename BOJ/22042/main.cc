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
const int div100[] = {1, 2, 4, 5, 10, 20, 25, 50};
lld N, A[MN];
bool D[100][100]; // percent (common divisor, sum)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  lld sum = 0;
  for (int i=1; i<=N; i++) { cin >> A[i]; sum += A[i]; }

  for (auto g: div100) D[g][0] = 1;

  for (int i=1; i<=N; i++) {
    for (auto g: div100) {
      if (A[i] % g != 0) continue;
      for (int p=100-g; p>=0; p-=g) {
        if (p-A[i] >= 0) D[g][p] |= D[g][p-A[i]];
      }
    }
  }

  vector<lld> ans = {sum};

  for (auto g: div100) {
    for (int p=0; p<100 && p<sum; p+=g) {
      if (!D[g][p]) continue;

      if ((sum-p) * 100 % (100-p) != 0) continue;
      lld tot = (sum-p) * 100 / (100-p);
      if (tot * g % 100 == 0) ans.push_back(tot);
    }
  }

  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());

  cout << sz(ans) << endl;
  for (auto x: ans) cout << x << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
