#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 2505;
string S;
vector<int> P[MAX_N];
int D[MAX_N];

void getPalin() {
  for (int i = 0; i < S.length(); i++) {
    int r = 0;
    while (0 <= i - r && i + r < S.length()) {
      if (S[i - r] == S[i + r]) {
        r++;
        P[i + r].push_back(r * 2 - 1);
      } else {
        break;
      }
    }

    r = 0;
    while (0 <= i - r - 1 && i + r < S.length()) {
      if (S[i - r - 1] == S[i + r]) {
        r++;
        P[i + r].push_back(r * 2);
      } else {
        break;
      }
    }
  }
}

void dp() {
  fill(D, D + MAX_N, MAX_N);
  D[0] = 0;

  for (int i = 0; i <= S.length(); i++) {
    for (int j = 0; j < P[i].size(); j++) {
      D[i] = min(D[i], D[i - P[i][j]] + 1);
    }
  }

  cout << D[S.length()] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> S;
  getPalin();
  dp();

  // for (int i = 1; i <= S.length(); i++) {
  //   cout << i << ": ";
  //   for (int j = 0; j < P[i].size(); j++) {
  //     cout << P[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  ////////////////////////////////
  return 0;
}
