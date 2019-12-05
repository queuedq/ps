#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 2e5 + 5;
int N;
int idx[MAX_N];
int ans[MAX_N];

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int w; cin >> w;
    idx[w] = i;
  }
}

void calc() {
  int l = INT_MAX, r = INT_MIN;

  for (int i = 1; i <= N; i++) { // is i beautiful?
    int j = idx[i];
    l = min(l, j);
    r = max(r, j);

    if (r - l + 1 == i) {
      ans[i] = 1;
    } else {
      ans[i] = 0;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    calc();
  }

  ////////////////////////////////
  return 0;
}
