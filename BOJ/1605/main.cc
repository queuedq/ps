#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
int L;
string S;

struct Hash {
  lld h1 = 0, h2 = 0, p1 = 1, p2 = 1;

  Hash(int len) {
    while (len--) {
      p1 = p1*33 % MOD1;
      p2 = p2*33 % MOD2;
    }
  }

  void roll(int back, int front=0) {
    h1 = (h1*33 + back) % MOD1;
    h1 = (h1 - p1*front) % MOD1;
    h1 = (h1+MOD1) % MOD1;
    h2 = (h2*33 + back) % MOD2;
    h2 = (h2 - p2*front) % MOD2;
    h2 = (h2+MOD2) % MOD2;
  }

  pll repr() {
    return {h1, h2};
  }
};

bool check(int len) {
  set<pll> hashes;
  Hash hash(len);

  for (int i=0; i<len; i++) {
    hash.roll(S[i]-'a'+1);
  }
  hashes.insert(hash.repr());

  for (int i=len; i<S.size(); i++) {
    hash.roll(S[i]-'a'+1, S[i-len]-'a'+1);
    if (hashes.find(hash.repr()) != hashes.end()) return true;
    hashes.insert(hash.repr());
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> S;

  int l = 0, r = S.size();
  while (l+1 < r) {
    int mid = (l+r)/2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
