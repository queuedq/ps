#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld round(lld N, int pos) {
  for (int i=0; i<pos; i++) N /= 10;
  int up = N%10 >= 5;
  N /= 10;
  N += up;
  N *= 10;
  for (int i=0; i<pos; i++) N *= 10;
  return N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld N; cin >> N;
  for (int i=0; i<15; i++) {
    lld N1 = round(N, i);
    if (N1 > N) N = N1;
  }
  cout << N;

  ////////////////////////////////
  return 0;
}
