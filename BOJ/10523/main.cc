#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, p;
pll P[MAXN];

pll operator +(pll a, pll b) { return {a.first + b.first, a.second + b.second}; }
pll operator -(pll a, pll b) { return {a.first - b.first, a.second - b.second}; }
lld cross(pll a, pll b) { return a.first * b.second - a.second * b.first; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> p;
  if (N == 1) { cout << "possible" << endl; return 0; }
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    P[i] = {x, y};
  }

  bool ans = false;
  for (int t=0; t<200; t++) {
    int i = 0, j = 0;
    while (i == j) {
      i = rand() % N;
      j = rand() % N;
    }

    int line = 0;
    for (int k=0; k<N; k++) {
      if (cross(P[i] - P[k], P[j] - P[k]) == 0) line++;
    }

    if (line*100 >= p*N) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "possible" : "impossible") << endl;

  ////////////////////////////////
  return 0;
}
