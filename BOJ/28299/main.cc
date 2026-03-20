#include <bits/stdc++.h>
#include <ostream>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
const lld MOD = 998'244'353;

struct mint {
  lld x;

  mint pow(lld e) {
    if (e == 0) return {1};
    mint r = pow(e/2);
    if (e%2) return r * r * (*this);
    return r * r;
  }
  mint inv() { return pow(MOD-2); }

  mint operator+(mint a) const { return {(x+a.x) % MOD}; }
  mint operator-(mint a) const { return {(x-a.x+MOD) % MOD}; }
  mint operator*(mint a) const { return {(x*a.x) % MOD}; }
  mint operator/(mint a) const { return (*this)*a.inv(); }

  mint operator+=(mint a) { return *this=(*this+a); }
  mint operator-=(mint a) { return *this=(*this-a); }
  mint operator*=(mint a) { return *this=(*this*a); }
  mint operator/=(mint a) { return *this=(*this/a); }
};
mint _0 = mint{0}, _1 = mint{1}, _2 = mint{2}, _3 = mint{3}, _4 = mint{4}, _6 = mint{6};

ostream& operator<<(ostream &os, mint a) { return os << a.x; }

lld N;
mint A[MN], A2[MN], A3[MN], A4[MN];
mint S[MN], S2[MN];
mint T, T2, T3, T4, X4;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i].x;
    A2[i] = A[i] * (A[i]-_1);
    A3[i] = A2[i] * (A[i]-_2);
    A4[i] = A3[i] * (A[i]-_3);
    S[i+1] = S[i] + A[i];
    S2[i+1] = S2[i] + A2[i];
    T += A[i];
    T2 += A2[i];
    T3 += A3[i];
    T4 += A4[i];
  }

  for (int i=0; i<N; i++) X4 += S2[i] * A2[i];
  X4 = X4 * _2 + T4;

  // this counts all ((i,j), (k,l)) inversion pairs where i<j, k<l
  // 1. pick 2, 3, or 4 elements (no order)
  // 2. pair them (with order)
  // 3. assign numbers, so that each pair becomes inversion
  // 3-a. or just assign different numbers to each pair
  // 3-b. and give them order

  // ij kl: 6 pairings
  mint E1 = T * (T-_1) * (T-_2) * (T-_3) - T2 * (T-_2) * (T-_3) * _2 + X4; // 3-a
  E1 /= _4; // 3-b
  // ij jk: 2 pairings
  mint E2 = _0;
  for (int i=0; i<N; i++) E2 += A[i] * S[i] * (T - S[i+1]);
  // ij ik: 2 pairings
  mint E3 = _0;
  for (int i=0; i<N; i++) E3 += A[i] * (T - S[i+1]) * (T - S[i+1] - _1);
  // ik jk: 2 pairings
  mint E4 = _0;
  for (int i=0; i<N; i++) E4 += A[i] * S[i] * (S[i] - _1);
  // ij ij: 1 pairings
  mint E5 = _0;
  for (int i=0; i<N; i++) E5 += A[i] * S[i];

  // cout << E1 << " " << E2 << " " << E3 << " " << E4 << " " << E5 << endl;

  mint ans = E1 / (_4*_3*_2*_1) * _6 +
             E2 / (_3*_2*_1) * _2 +
             E3 / (_3*_2*_1) * _2 +
             E4 / (_3*_2*_1) * _2 +
             E5 / (_2*_1);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
