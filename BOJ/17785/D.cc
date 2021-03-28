#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e12+5;

lld gcd(lld a, lld b) {
  while (b > 0) { a = a % b; swap(a, b); }
  return a;
}

lld lcm(lld a, lld b) {
  return a / gcd(a, b) * b;
}

pll egcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld invmod(lld a, lld m) {
  return (egcd(a, m).first + m) % m;
}

lld crt(lld a, lld m, lld b, lld n) {
  auto [u, v] = egcd(m, n);
  lld g = u*m + v*n;
  lld l = m/g*n;
  return ((((__int128)a*v*n + (__int128)b*u*m) / g) % l + l) % l;
}

////////////////////////////////////////////////////////////////
int N;
vector<int> A, B, vst;
vector<vector<int>> ab, ba;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A.push_back(a-1);
  }
  for (int i=0; i<N; i++) {
    int b; cin >> b;
    B.push_back(b-1);
  }
  vst.resize(N);

  int p = 0;
  ab.push_back({});
  while (true) {
    if (vst[p]) {
      while (p < N && vst[p]) p++;
      if (p == N) break;
      ab.push_back({});
    }

    vst[p] = 1;
    ab.back().push_back(p);
    p = B[A[p]];
  }

  vst.clear();
  vst.resize(N);
  p = 0;
  ba.push_back({});
  while (true) {
    if (vst[p]) {
      while (p < N && vst[p]) p++;
      if (p == N) break;
      ba.push_back({});
    }

    vst[p] = 1;
    ba.back().push_back(p);
    p = A[B[p]];
  }

  lld ans = 1;
  for (auto cyc: ab) {
    ans = lcm(ans, cyc.size());
    if (ans > INF) break;
  }
  ans *= 2;

  ////////////////////////////////

  vector<lld> modulus, remainder;
  bool ok = true;
  for (auto cyc: ba) {
    int m = cyc.size(), r = 0;

    int p = A[cyc[0]];
    for (; r<=m; r++) {
      if (p == cyc[0]) break;
      p = A[B[p]];
    }

    if (r >= m) ok = false;
    for (int i=0; i<m; i++) {
      if (A[cyc[i]] != cyc[(i+m-r) % m]) ok = false;
    }
    if (!ok) break;

    modulus.push_back(m);
    remainder.push_back(r);
  }

  ////////////////////////////////

  lld m = 1, r = 0;
  if (ok) {
    for (int i=0; i<modulus.size(); i++) {
      lld g = gcd(m, modulus[i]);
      if ((r - remainder[i]) % g != 0) { ok = false; break; }

      auto rr = crt(r, m, remainder[i], modulus[i]);
      m = m / g * modulus[i], r = rr;

      if (m > INF) break; // r can't get bigger
    }

    // check whether r is correct in case of m overflow
    for (auto cyc: ba) {
      for (int i=0; i<cyc.size(); i++) {
        lld m = cyc.size();
        if (A[cyc[i]] != cyc[((i-r) % m + m) % m]) {
          ok = false;
        }
      }
    }
  }

  if (ok) ans = min(ans, 1+r*2);
  if (ans > (lld)1e12) cout << "huge" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
