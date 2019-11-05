#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
int T;
int a, b, c;

int calc() {
  cin >> a >> b >> c;
  int score = 0;
  for (int x = 0; x <= a; x++) {
    int y = min(b - 2 * x, c / 2);
    score = max(score, 3 * x + 3 * y);
  }
  return score;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
