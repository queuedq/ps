#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

typedef __int128 llld;
ostream& operator <<(ostream &os, llld num) {
  lld m = 1'000'000'000'000'000'000;
  string str;
  do {
    lld digits = num % m;
    auto digitsStr = to_string(digits);
    auto leading0s = (digits != num) ? string(18 - digitsStr.length(), '0') : "";
    str = leading0s + digitsStr + str;
    num = (num - digits) / m;
  } while (num != 0);
  os << str;
  return os;
}

////////////////////////////////////////////////////////////////
// const llld P = 1'000'000'000'000'000'000 + 3;
const llld P = 7'136'575'235'687'874'751;
int N;
vector<llld> A, B;
llld F;
vector<llld> C;

llld modinv(llld a, llld b) {
  llld aa = a;
  llld m = b;
  llld s0 = 1, s1 = 0, t0 = 0, t1 = 1;
  while (b > 0) {
    llld q = a / b;
    a -= b * q; s0 -= t0 * q; s1 -= t1 * q;
    swap(a, b); swap(s0, t0); swap(s1, t1);
  }
  return (s0 % m + m) % m;
}

void input() {
  cin >> N;
  cin.get(); // Remove '\n'

  for (int i = 0; i < N; i++) {
    llld a = 0, b = 0;
    while (true) {
      char digit = cin.get();
      if (digit == '/') { break; }
      a = (a * 10 + (digit - '0')) % P;
    }
    while (true) {
      char digit = cin.get();
      if (digit == '\n') { break; }
      b = (b * 10 + (digit - '0')) % P;
    }
    A.push_back(a);
    B.push_back(b);
  }
}

void cf(vector<llld> &c, llld a, llld b) {
  // Continued fraction of a/b
  // c: coefficients
  while (b > 0) {
    llld q = a / b;
    c.push_back(q);
    a = a % b; swap(a, b);
  }
}

void getFrac() {
  llld a = 1, b = 1;
  for (int i = 0; i < A.size(); i++) {
    a = a * A[i] % P;
    b = b * B[i] % P;
  }
  F = a * modinv(b, P) % P;
  // cout << a << " " << b << " " << F << endl;
  // assert(a != 0 && b != 0);

  cf(C, F, P);

  llld p = 1, pp = 0, q = 0, qq = 1;
  for (int i = 0; i < C.size(); i++) {
    swap(p, pp); swap(q, qq);
    p = C[i] * pp + p;
    q = C[i] * qq + q;
    llld numer = F * q - P * p;
    // cout << C[i] << endl;
    // cout << p << " " << q << " " << F * q - P * p << endl;
    if (q <= 1'000'000'000 && numer >= 0 && numer <= 1'000'000'000) {
      cout << numer << "/" << q << endl;
      return;
    }
  }

  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  getFrac();

  ////////////////////////////////
  return 0;
}
