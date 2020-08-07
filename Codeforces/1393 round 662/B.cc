#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, Q, cnt[MAXN], cnt2, cnt4;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    cnt[a]++;
  }

  for (int i=1; i<MAXN; i++) {
    cnt2 += cnt[i] / 2;
    cnt4 += cnt[i] / 4;
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {

    string s; int x; cin >> s >> x;
    if (s == "+") {
      cnt[x]++;
      if (cnt[x] % 2 == 0) cnt2++;
      if (cnt[x] % 4 == 0) cnt4++;
    } else {
      cnt[x]--;
      if (cnt[x] % 2 == 1) cnt2--;
      if (cnt[x] % 4 == 3) cnt4--;
    }

    if (cnt2 >= 4 && cnt4 >= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
