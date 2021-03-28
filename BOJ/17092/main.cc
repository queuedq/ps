#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld H, W, N, ans[10];
unordered_map<lld, int> cnt;

lld hash_pair(int i, int j) { return (i-1)*W + j-1; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> H >> W >> N;

  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    for (int dx=-2; dx<=0; dx++) {
      for (int dy=-2; dy<=0; dy++) {
        if (a+dx >= 1 && a+dx+2 <= H && b+dy >= 1 && b+dy+2 <= W) {
          cnt[hash_pair(a+dx, b+dy)]++;
        }
      }
    }
  }

  ans[0] = (H-2)*(W-2);
  for (auto [p, x]: cnt) {
    ans[0]--;
    ans[x]++;
  }

  for (int i=0; i<=9; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
