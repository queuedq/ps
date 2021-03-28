#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  lld one = 0, two = 0, tot = 0;
  for (int i=0; i<N; i++) {
    lld A; cin >> A;
    one += A % 2;
    two += A / 2;
    tot += A;
  }

  if (tot % 3 != 0 || one > two) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  ////////////////////////////////
  return 0;
}
