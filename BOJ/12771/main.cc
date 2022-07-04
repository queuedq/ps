#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
lld N, X0[MN], X1[MN], Y[MN];

struct Fraction {
  lld a, b;
  Fraction (lld a, lld b): a(a), b(b) { if (b < 0) this->a = -a, this->b = -b; }
  bool operator ==(const Fraction &F) const { return a * F.b == F.a * b; }
  bool operator <(const Fraction &F) const { return a * F.b < F.a * b; }
};

struct Event {
  Fraction f; lld w, t;
  bool operator <(const Event &E) const {
    if (f == E.f) return t < E.t;
    return f < E.f;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> X0[i] >> X1[i] >> Y[i];
    if (X1[i] < X0[i]) swap(X0[i], X1[i]);
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    vector<Event> E;
    for (int j=0; j<N; j++) {
      if (Y[i] == Y[j]) continue;
      Fraction f0 = {X0[j] - X0[i], Y[j] - Y[i]};
      Fraction f1 = {X1[j] - X0[i], Y[j] - Y[i]};
      if (f1 < f0) swap(f0, f1);
      E.push_back({f0, X1[j] - X0[j], 0});
      E.push_back({f1, X1[j] - X0[j], 1});
    }
    sort(all(E));

    lld res = X1[i] - X0[i];
    ans = max(ans, res);
    for (auto [f, w, t]: E) {
      if (t == 0) res += w;
      else res -= w;
      ans = max(ans, res);
    }
    assert(res == X1[i] - X0[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
