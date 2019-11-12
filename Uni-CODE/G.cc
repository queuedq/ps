#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

template<typename T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "{";
  if (vec.size() > 0) {
    copy(vec.begin(), vec.end() - 1, ostream_iterator<T>(os, ", "));
    os << *(vec.end() - 1);
  }
  os << "}";
  return os;
}

////////////////////////////////////////////////
#define MAX_N 200005
lld P1 = 9999991, P2 = 9999973;
int N;
string S;

struct Hash {
  lld h1, h2;
  int index;
};
vector<Hash> hashes;

bool compHash(Hash a, Hash b) {
  pii aHash = {a.h1, a.h2};
  pii bHash = {b.h1, b.h2};
  if (aHash == bHash) {
    return a.index < b.index;
  } else {
    return aHash < bHash;
  }
}

ostream& operator <<(ostream& os, Hash h) {
  os << "[" << h.h1 << ", " << h.h2 << ", " << h.index << "]";
  return os;
}

void input() {
  cin >> S;
  N = S.size();
}

bool hashTest(int len) {
  // Initialize
  hashes.clear();

  lld pow1 = 1, pow2 = 1;
  for (int i = 0; i < len - 1; i++) {
    pow1 = (pow1 * 26) % P1;
    pow2 = (pow2 * 26) % P2;
  }

  // First Hash
  lld h1 = 0, h2 = 0;
  for (int i = 0; i < len; i++) {
    h1 = (h1 * 26 + S[i] - 'a') % P1;
    h2 = (h2 * 26 + S[i] - 'a') % P2;
  }
  hashes.push_back({h1, h2, 0});

  // Roll
  for (int i = 1; i <= N - len; i++) {
    h1 = (h1 - pow1 * (S[i - 1] - 'a')) % P1 + P1;
    h2 = (h2 - pow2 * (S[i - 1] - 'a')) % P2 + P2;
    h1 = (h1 * 26 + S[i + len - 1] - 'a') % P1;
    h2 = (h2 * 26 + S[i + len - 1] - 'a') % P2;
    hashes.push_back({h1, h2, i});
  }

  // Test
  sort(hashes.begin(), hashes.end(), compHash);
  // cout << hashes << endl;
  int i = 0;
  while (i < hashes.size()) {
    Hash left = hashes[i];
    while (i < hashes.size() && hashes[i].h1 == left.h1 && hashes[i].h2 == left.h2) {
      i++;
    }
    int leftIdx = left.index;
    int rightIdx = hashes[i - 1].index;
    if (rightIdx - leftIdx >= len) {
      return true;
    }
  }
  return false;
}

int search() {
  int l = 0, r = N + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (hashTest(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  if (l == 0) {
    return -1;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  // cout << hashTest(7) << endl;
  cout << search() << endl;

  ////////////////////////////////
  return 0;
}
