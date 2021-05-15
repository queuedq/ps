#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'000'005;

int N;
lld D[MN], E[MN];
vector<int> divisors[MN];

void preprocess() {
  for (int i=2; i<MN; i++) {
    for (int j=i; j<MN; j+=i) {
      divisors[j].push_back(i);
    }
  }

  for (int i=1; i<MN; i++) {
    for (auto d: divisors[i]) {
      D[i] = max(D[i], D[i/d - 1] + 1);
    }
  }

  for (int i=1; i<MN; i++) {
    for (auto d: divisors[i]) {
      if (d == 2) continue;
      E[i] = max(E[i], D[i/d - 1] + 1);
    }

    // if (i < 50) cout << i << " " << E[i] << endl;
  }
}

void solve(int test) {
  cin >> N;
  cout << "Case #" << test << ": " << E[N] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  preprocess();

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
