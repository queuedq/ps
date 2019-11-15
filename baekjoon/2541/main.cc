#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int a, b, d;

int sign(int x) {
  if (x > 0) { return 1; }
  else if (x == 0) { return 0; }
  else { return -1; }
}

bool test(int p, int q) {
  if (d == 0) { return p == q; }
  if (sign(a - b) != sign(p - q)) { return false; }
  return (p - q) % d == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> a >> b;
  d = abs(a - b);
  while (d > 0 && d % 2 == 0) { d /= 2; }

  for (int i = 0; i < 5; i++) {
    int p, q; cin >> p >> q;
    if (test(p, q)) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
