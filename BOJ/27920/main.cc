#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, ans[MN];
vector<int> ord;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1, num=N, dir=1; num>=1; num--, dir*=-1) {
    ans[i] = num;
    ord.push_back(i);
    i += (num-1) * dir;
  }
  reverse(all(ord));

  cout << "YES" << endl;
  for (int i=1; i<=N; i++) cout << ans[i] << " ";
  cout << endl;
  for (int i=0; i<N; i++) cout << ord[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
