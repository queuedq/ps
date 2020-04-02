#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct LIS {
  lld val, cnt, sum;

  bool operator<(const LIS t) const { return val > t.val; }
};

const lld MOD  = 1e9+7;
const int MAXN = 1e6+5;
int N, A[MAXN];
vector<LIS> lis[MAXN]; // lis[i]: info about LIS of length i

int lisLen(int val) {
  int l = 0, r = N;
  while (l+1 < r) {
    int mid = (l+r) / 2;
    if (!lis[mid].empty() && val > lis[mid].rbegin()->val) l = mid;
    else r = mid;
  }
  return r;
}

lld lisCnt(int len, int val) {
  if (len == 1) return 1;
  LIS s = *upper_bound(lis[len-1].begin(), lis[len-1].end(), (LIS){val, 0, 0});
  return (lis[len-1].rbegin()->sum - s.sum + s.cnt + MOD) % MOD;
}

void printLis() {
  for (int i=1; i<=N; i++) {
    if (lis[i].empty()) return;
    LIS l = *lis[i].rbegin();
    cout << l.val << " " << l.cnt << " " << l.sum << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  int maxlen = 0;
  for (int i=1; i<=N; i++) {
    int len = lisLen(A[i]);
    lld cnt = lisCnt(len, A[i]);
    lld sum = ((lis[len].empty() ? 0 : lis[len].rbegin()->sum) + cnt) % MOD;
    lis[len].push_back({A[i], cnt, sum});

    maxlen = max(maxlen, len);
  }

  cout << maxlen << " " << lis[maxlen].rbegin()->sum << endl;

  ////////////////////////////////
  return 0;
}
