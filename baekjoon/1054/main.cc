#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
string A[13];

struct Partial {
  string prefix, suffix;

  void reduce() {
    int i = 0, ps = prefix.size(), ss = suffix.size();
    while (i < ps && i < ss) {
      if (prefix[i] != suffix[ss-i-1]) break;
      i++;
    }
    prefix = prefix.substr(i, ps-i);
    suffix = suffix.substr(0, ss-i);
  }

  bool valid() {
    return prefix == "" || suffix == "";
  }

  bool operator ==(const Partial &p) const { return prefix == p.prefix && suffix == p.suffix; }
};

struct Hash {
  size_t operator ()(const Partial& p) const {
    return hash<string>()(p.prefix) ^ hash<string>()(p.suffix);
  };
};

unordered_map<Partial, int, Hash> D[1<<13];

bool isPalindrome(const string &s) {
  int len = s.size();
  for (int i=0; i<len; i++) {
    if (s[i] != s[len-i-1]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  D[0][{"", ""}] = 1;

  for (int m=0; m<(1<<N); m++) {
    for (int i=0; i<N; i++) {
      if (!(m & 1<<i)) continue;
      int k = m - (1<<i);

      for (auto [p, cnt]: D[k]) {
        Partial q = {p.prefix, p.suffix};
        if (q.prefix == "") q.prefix = A[i];
        else q.suffix = A[i];
        q.reduce();

        if (q.valid()) D[m][q] += cnt;
      }
    }
  }

  lld ans = 0;
  for (int m=1; m<(1<<N); m++) {
    for (auto [p, cnt]: D[m]) {
      if (isPalindrome(p.prefix) && isPalindrome(p.suffix)) {
        // cout << m << ": " << p.prefix << "**" << p.suffix << ": " << cnt << endl;
        ans += cnt;
      }
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
