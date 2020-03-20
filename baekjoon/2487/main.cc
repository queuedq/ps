#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e4 + 5;
int N, A[MAXN], vst[MAXN];

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b > 0) { int r = a % b; a = b; b = r; }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  int ans = 1;

  for (int i=1; i<=N; i++) {
    if (vst[i]) continue;
    vst[i] = true;
    int j = A[i], cycle = 1;
    while (j != i) {
      vst[j] = true;
      j = A[j];
      cycle++;
    }
    ans = ans / gcd(ans, cycle) * cycle;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
