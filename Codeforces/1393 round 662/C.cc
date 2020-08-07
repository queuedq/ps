#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int T, N, cnt[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    for (int i=1; i<=N; i++) {
      int a; cin >> a;
      cnt[a]++;
    }

    int mx = 0, num = 0;
    for (int i=1; i<=N; i++) {
      if (cnt[i] == mx) {
        num++;
      } else if (cnt[i] > mx) {
        mx = cnt[i];
        num = 1;
      }
    }

    cout << (N-num) / (mx-1) - 1 << endl;

    for (int i=1; i<=N; i++) cnt[i] = 0;
  }


  ////////////////////////////////
  return 0;
}
