#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N;
double D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=6; j++) {
      D[i] += (D[max(i-j, 0)] + 1) / 6;
    }
  }
  cout << fixed << setprecision(10) << D[N] << endl;

  ////////////////////////////////
  return 0;
}
