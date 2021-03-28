#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

// Start Here
#define INF 987654321

int n, a[1000], b[1000];
int D[2][100005];

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= 100005; j++) {
      D[i][j] = INF;
    }
  }

  D[0][0] = b[0];
  D[0][a[0]] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 100005; j++) {
      if (j - a[i] < 0) {
        D[1][j] = min(D[0][j] + b[i], INF);
      } else {
        D[1][j] = min(min(D[0][j-a[i]], D[0][j]+b[i]), INF);
      }
    }
    for (int j = 0; j <= 100005; j++) {
      D[0][j] = D[1][j];
    }
  }

  int result = INF;
  for (int i = 0; i <= 100005; i++) {
    result = min(result, max(i, D[0][i]));
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Code Here

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
