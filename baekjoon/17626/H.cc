#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

int D[50005];
int N;

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;

  D[1] = 1;
  for (int i = 1; i <= N; i++) {
    D[i] = INT_MAX;
    for (int j = 1; j <= sqrt(i); j++) {
      D[i] = min(D[i], D[i - j * j] + 1);
    }
  }

  cout << D[N];

  return 0;
}
