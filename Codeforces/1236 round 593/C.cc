#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 300
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i = 1; i <= N; i++) {
    int group[MAX_N + 1];
    for (int j = 1; j <= N; j++) {
      if (j % 2 == 1) {
        group[j] = N * (j - 1) + i;
      } else {
        group[j] = N * j - i + 1;
      }
    }
    for (int j = 1; j < N; j++) {
      cout << group[j] << " ";
    }
    cout << group[N] << endl;
  }

  ////////////////////////////////
  return 0;
}
