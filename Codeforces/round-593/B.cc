#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
int n, m, mod = 1000000007;

int powmod(int a, int b, int n){
  lld x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) x = (x * y) % n;
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  cout << powmod(powmod(2, m, mod) - 1, n, mod) << endl;;

  ////////////////////////////////
  return 0;
}
