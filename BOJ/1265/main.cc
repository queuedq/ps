#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct BigInt {
  static const int BASE = 1e8;
  vector<int> arr;

  BigInt() { }
  BigInt(const BigInt &x) { arr = x.arr; }
  BigInt(int val) {
    while (val > 0) {
      arr.push_back(val % BASE);
      val /= BASE;
    }
  }

  BigInt& operator +=(const BigInt &x) {
    arr.resize(max(arr.size(), x.arr.size()));
    int c = 0;
    for (int i = 0; i < arr.size(); i++) {
      arr[i] += (i < x.arr.size() ? x.arr[i] : 0) + c;
      if (c = arr[i] >= BASE) arr[i] -= BASE;
    }
    if (c > 0) arr.push_back(c);
    return *this;
  }

  BigInt operator +(const BigInt &x) const {
    return BigInt(*this) += x;
  }
};

ostream& operator <<(ostream &os, BigInt &x) {
  if (x.arr.empty()) return os << 0;
  os << x.arr.back();
  for (int i = x.arr.size()-2; i >= 0; i--) {
    os << setfill('0') << setw(8) << x.arr[i];
  }
  return os;
}

const int MAXN = 105;
const int MAXP = 1 << 12;
int N, K;
BigInt D[MAXN][MAXP];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;

  D[0][0] = 1;

  for (int i=1; i<=N; i++) {
    for (int m = 0; m < 1 << (K*2); m++) {
      for (int d=-K; d<=K; d++) {
        if (i+d < 1 || i+d > N) continue;
        if (m & (1<<(d+K))) continue;
        int mask = m | (1<<(d+K));
        mask = mask >> 1;
        D[i][mask] += D[i-1][m];
      }
    }
  }

  BigInt ans = 0;
  for (int m = 0; m < 1 << (K*2); m++) {
    ans += D[N][m];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
