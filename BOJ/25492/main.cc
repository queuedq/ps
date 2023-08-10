#include <bits/stdc++.h>
#include <climits>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MN = 202020;
lld N, C[MN], B[MN], base;
lld A[MN], D[MN];
// base: base cost (all columns removed)
// A: cost to install ith column

struct Event {
  // i: pos where gcd changes
  // g: gcd from ith column to current pos
  // dp: min dp until next change
  lld i, g, dp;

  Event merge(Event E) { return {i, g, min(dp, E.dp)}; } // merge same gcd
};
list<Event> E;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> C[i];
  for (int i=0; i<N; i++) cin >> B[i];

  A[0] = C[0], A[N-1] = C[N-1];
  for (int i=1; i<N-1; i++) {
    A[i] = C[i] * 2 - B[i]; // cost to use ith column
    base += B[i];
  }

  D[0] = A[0];
  for (int i=1; i<N; i++) {
    E.push_back({i-1, C[i-1], D[i-1]}); // add prev pos
    for (auto &[j, g, dp]: E) g = gcd(g, C[i]); // update gcds

    // merge events
    for (auto it=E.begin(), nt=next(it); nt!=E.end(); ) {
      if (it->g == nt->g) {
        *it = it->merge(*nt);
        nt = E.erase(nt);
      } else {
        it++, nt++;
      }
    }

    // dp
    D[i] = LLONG_MAX;
    for (auto [j, g, dp]: E) {
      D[i] = min(D[i], dp - g * 2 + A[i]);
    }
  }

  cout << base + D[N-1] << endl;

  ////////////////////////////////
  return 0;
}
