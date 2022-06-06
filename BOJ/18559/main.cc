#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+1;
int N, prime[MN], mu[MN];
vector<int> pf[MN], nf[MN];

struct Poly {
  vector<lld> a;

  Poly() {}
  Poly(int d): a(vector<lld>(d+1)) {}
  Poly(initializer_list<lld> a): a(a) {}

  inline int deg() const { return (int)a.size()-1; }

  Poly& operator =(Poly P) { a = P.a; return *this; }

  bool operator <(const Poly &P) const {
    if (deg() != P.deg()) return deg() < P.deg();
    for (int i=deg(); i>=0; i--)
      if (a[i] != P.a[i]) return a[i] < P.a[i];
    return false;
  }

  Poly mul(int n) const { // mul by (x^n - 1)
    Poly Q(deg() + n);
    for (int i=0; i<=deg(); i++) {
      Q.a[i] -= a[i];
      Q.a[i+n] += a[i];
    }
    return Q;
  }

  Poly div(int n) const { // div by (x^n - 1)
    Poly Q(deg() - n), R = *this;
    for (int i=deg(); i>=n; i--) {
      Q.a[i-n] = R.a[i];
      R.a[i-n] += R.a[i];
    }
    return Q;
  }
};

string term(lld a, int d, bool first) {
  string res = "";
  if (a == 0) return res;
  if (!first || a < 0) res += a > 0 ? "+" : "-";
  if (abs(a) != 1 || d == 0) res += to_string(abs(a));
  if (d == 0) return res;
  if (d == 1) return res + "x";
  return res + "x^" + to_string(d);
}

ostream& operator <<(ostream &os, const Poly &P) {
  bool first = 1;
  for (int i=P.deg(); i>=0; i--) {
    if (P.a[i]) {
      os << term(P.a[i], i, first);
      first = 0;
    }
  }
  return os;
}

Poly cyclotomic(lld n) {
  Poly P(0); P.a[0] = 1;
  for (auto d: pf[n]) P = P.mul(d);
  for (auto d: nf[n]) P = P.div(d);
  return P;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime+2, prime+MN, 1);
  mu[1] = 1;
  for (lld p=2; p<MN; p++) {
    if (prime[p]) {
      mu[p] = -1;
      for (lld n=p*2; n<MN; n+=p) {
        prime[n] = 0;
        mu[n] = -mu[n/p];
      }
      for (lld n=p*p; n<MN; n+=p*p) mu[n] = 0;
    }
  }

  for (lld d=1; d<MN; d++) {
    for (lld n=d; n<MN; n+=d) {
      if (mu[d] == 1) pf[n].push_back(n/d);
      if (mu[d] == -1) nf[n].push_back(n/d);
    }
  }

  int T; cin >> T;
  while (T--) {
    cin >> N;

    vector<Poly> C;
    for (lld d=1; d<=N; d++) {
      if (N%d == 0) C.push_back(cyclotomic(d));
    }
    sort(all(C));

    for (auto P: C) cout << '(' << P << ')';
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
