#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

// Start Here

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Code Here
  cin >> n;
  int res = 1;

  for (int i = 0; i < (n + 1) / 2; i++) {
    res = res * 2 % 16769023;
  }

  cout << res;

  return 0;
}
