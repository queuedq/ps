#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 1e5+5;
int N, K;

void solve1() {
  int _; cin >> _ >> _;
  
  lld sum = 0;
  for (int i=1; i<=N; i++) {
    cout << "T " << i << endl;
    int R, P; cin >> R >> P;
    sum += P;
  }

  cout << "E " << (sum / 2) << endl;
}

void solve2() {
  int _; cin >> _ >> _;
  
  double sum = 0;
  for (int i=1; i<=K; i++) {
    cout << "T " << (rand() % N + 1) << endl;
    int R, P; cin >> R >> P;
    sum += P;
  }

  cout << "E " << (lld)(sum / K * N / 2) << endl;
}

void solve(int test) {
  cin >> N >> K;
  if (N <= K) solve1();
  else solve2();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
