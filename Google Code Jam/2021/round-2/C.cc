#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld gcd(lld a, lld b) {
  while (b > 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
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

////////////////////////////////////////////////////////////////
const int MN = 100'005;
const lld MOD = 1e9 + 7;
lld fact[MN], invfact[MN];
int N, V[MN];

lld binom(lld n, lld k) {
  lld den = (invfact[k] * invfact[n-k] % MOD);
  return fact[n] * den % MOD;
}

void solve(int test) {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> V[i];
  V[N+1] = 1;

  lld ans = 1;
  vector<int> st;
  st.push_back(0);

  for (int i=1; i<=N+1; i++) {
    if (V[i] > V[i-1]+1) { ans = 0; break; }

    while (st.size()-1 >= V[i]) {
      int a = st[st.size()-2], b = st[st.size()-1];
      ans = ans * binom(i-a-2, i-b-1) % MOD;
      st.pop_back();
    }
    st.push_back(i);
  }

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fact[0] = invfact[0] = 1;
  for (int i=1; i<MN; i++) {
    fact[i] = fact[i-1] * i % MOD;
    invfact[i] = invmod(fact[i], MOD);
  }

  assert(binom(10, 7) == 120);

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
