#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

// Start Here
#define INF 987654321

int n, a[255], b[255];
int E[255][62505];

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int max(int a, int b) {
  return -min(-a, -b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Code Here
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 62500; j++) {
      E[i][j] = INF;
    }
  }

  E[0][0] = b[0];
  E[0][a[0]] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 62500; j++) {
      if (j - a[i] < 0) {
        E[i][j] = min(E[i-1][j] + b[i], INF);
      } else {
        E[i][j] = min(min(E[i-1][j-a[i]], E[i-1][j]+b[i]), INF);
      }
    }
  }

  // for (int i = 1; i < n; i++) {
  //   for (int j = 0; j < 20; j++) {
  //     cout << E[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  int result = INF;
  for (int i = 1; i < 62500; i++) {
    result = min(result, max(i, E[n-1][i]));
  }

  cout << result;

  return 0;
}
