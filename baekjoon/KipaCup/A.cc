#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int P = 65521;

lld gcd(lld a, lld b) {
  while (b > 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

pll xgcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld modinv(lld a, lld p) {
  return (xgcd(a, p).first + p) % p;
}

string nextStr(string s) {
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != 'z') { s[i] = s[i] + 1; return s; }
    s[i] = 'a';
  }
  return "";
}

bool check(string word, lld S, lld R) {
  lld sum = 0, ssum = 0;
  for (int i = 0; i < word.size(); i++) {
    sum += word[i] - 97;
    ssum += sum;
    sum %= P;
    ssum %= P;
  }
  if (sum == S && ssum == R) {
    return true;
  }
  return false;
}

string revAdler(lld adler0, lld adler1) {
  lld A0, A1, B0, B1;
  A0 = adler0 % (1L << 16);
  A1 = adler1 % (1L << 16);
  B0 = adler0 / (1L << 16);
  B1 = adler1 / (1L << 16);

  if (A1 - A0 != 1) { return "-1"; }

  lld len = B1 - B0;
  if (len <= 0) len += P;

  lld S = (A0 - len * 97) % P;
  lld R = (B0 - 97 * len * (len + 1) / 2) % P;
  if (S < 0) S += P;
  if (R < 0) R += P;

  // cout << S << " " << R << endl;
  string ans = "";

  if (len <= 5) {
    for (int i = 0; i < len; i++) {
      ans += 'a';
    }
    while (ans != "") {
      if (check(ans, S, R)) break;
      ans = nextStr(ans);
    }
  } else if (len < 6e4) {
    lld c = S * modinv(len, P) % P;
    if (c < 26 && c * len * (len + 1) / 2 % P == R) {
      ans = string(len, 'a' + c);
    }
  }

  if (ans == "") return "-1";
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld adler0, adler1;
  cin >> adler0 >> adler1;

  cout << revAdler(adler0, adler1) << endl;

  ////////////////////////////////
  return 0;
}
