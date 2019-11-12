#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

// Start Here
int n;
lld W, a[20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Code Here
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  lld money = W;
  lld coin = 0;

  for (int i = 0; i < n; i++) {
    if (a[i+1] > a[i]) {
      lld bought = money / a[i];
      coin += bought;
      money -= bought * a[i];
    } else {
      money += coin * a[i];
      coin = 0;
    }
  }

  cout << money;

  return 0;
}
