#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18+5;

struct BigInt {
  lld q = 0, r;

  BigInt(): r(0) { }
  BigInt(lld r): r(r) { }
  BigInt(lld q, lld r): q(q), r(r) { }
  BigInt operator +(BigInt a) {
    BigInt b(q + a.q, r + a.r);
    if (b.r >= INF) { b.r -= INF; b.q++; }
    return b;
  }
  BigInt operator -(BigInt a) {
    BigInt b(q - a.q, r - a.r);
    if (b.r < 0) { b.r += INF; b.q--; }
    return b;
  }
  BigInt normalize() { if (q > 0) return {1, 0}; else return *this; }
  bool operator <(BigInt a) { return q == a.q ? r < a.r : q < a.q; }
};

struct LIS {
  lld val; BigInt cnt, sum;

  bool operator<(const LIS t) const { return val < t.val; }
};

const int MAXN = 1e5+5;
lld N, K, A[MAXN];
vector<LIS> lis[MAXN]; // lis[i]: info about LIS of length i

int lisLen(lld val) {
  int l = 0, r = N;
  while (l+1 < r) {
    int mid = (l+r) / 2;
    if (!lis[mid].empty() && val < lis[mid].rbegin()->val) l = mid;
    else r = mid;
  }
  return r;
}

BigInt lisCnt(int len, int val) {
  if (len == 1) return 1;
  LIS s = *upper_bound(lis[len-1].begin(), lis[len-1].end(), (LIS){val, 0, 0});
  return (lis[len-1].rbegin()->sum - s.sum + s.cnt).normalize();
}

void printLis() {
  for (int i=1; i<=N; i++) {
    if (lis[i].empty()) return;
    cout << i << ": ";
    for (auto l: lis[i]) {
      cout << l.val << " " << l.cnt.r << " " << l.sum.r << " / ";
    } cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];

  int maxlen = 0;
  for (int i=N; i>=1; i--) {
    int len = lisLen(A[i]);
    BigInt cnt = lisCnt(len, A[i]);
    BigInt sum = (lis[len].empty() ? 0 : lis[len].rbegin()->sum) + cnt;
    lis[len].push_back({A[i], cnt, sum});

    maxlen = max(maxlen, len);
  }

  if (lis[maxlen].rbegin()->sum < K) {
    cout << -1 << endl;
    return 0;
  }

  vector<lld> ans;
  for (int len=maxlen; len>=1; len--) {
    int st = 0;
    if (len < maxlen) {
      st = upper_bound(lis[len].begin(), lis[len].end(), (LIS){*ans.rbegin(), 0, 0}) - lis[len].begin();
    }

    for (int i=st; i<lis[len].size(); i++) {
      BigInt cnt = lis[len][i].cnt;
      if (cnt < K) K -= cnt.r;
      else {
        ans.push_back(lis[len][i].val);
        break;
      }
    }
  }

  for (int i=0; i<ans.size(); i++) cout << ans[i] << " "; cout << endl;

  ////////////////////////////////
  return 0;
}
