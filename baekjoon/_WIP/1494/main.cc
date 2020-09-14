#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX = 10000;
lld N, S0, offset, g;
vector<pll> S;

lld getS(lld x) {
  if (x == 0) return S0;
  x -= offset;

  for (int i=0; i<S.size(); i++) {
    if (x < S[i].second/S[i].first*2) {
      if (x % 2 == 0) return S[i].first;
      return S[i].second - S[i].first*(x/2);
    }
  }

  if (x % 3 == 0) return 0;
  else return g;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld A, B; cin >> A >> B >> N;
  S0 = A;
  if (A > B) {
    A = abs(A-B);
    swap(A, B);
    offset = 1;
  }

  while (A > 0) {
    S.push_back({A, B});
    B %= A;
    swap(A, B);
  };
  g = B;

  for (int q=0; q<N; q++) {
    lld x; cin >> x;
    cout << getS(x) << endl;
  }

  ////////////////////////////////
  return 0;
}
