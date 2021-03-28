#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<vector<vector<int>>> pieces = {
  {{0}, {0, 0, 0, 0}},
  {{0, 0}},
  {{0, 0, 1}, {1, 0}},
  {{1, 0, 0}, {0, 1}},
  {{0, 0, 0}, {0, 1}, {1, 0, 1}, {1, 0}},
  {{0, 0, 0}, {0, 0}, {0, 1, 1}, {2, 0}},
  {{0, 0, 0}, {0, 0}, {1, 1, 0}, {0, 2}}
};

int A[105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int C, P; cin >> C >> P;
  for (int i=0; i<C; i++) cin >> A[i];

  int cnt = 0;

  for (auto p: pieces[P-1]) {
    int len = p.size();

    for (int i=0; i<C-len+1; i++) {
      bool ok = true;
      for (int j=1; j<len; j++) {
        if (A[i+j] - A[i+j-1] != p[j] - p[j-1]) {
          ok = false;
          break;
        }
      }
      if (ok) cnt++;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
