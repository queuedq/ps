#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
string P, H;
int pcnt[26], hcnt[105][26];

void check() {
  cin >> P >> H;

  for (int i = 0; i < 26; i++) pcnt[i] = 0;
  for (int i = 0; i <= H.size(); i++) {
    for (int j = 0; j < 26; j++) {
      hcnt[i][j] = 0;
    }
  }

  for (int i = 0; i < P.size(); i++) pcnt[P[i] - 'a']++;

  for (int i = 0; i <= H.size(); i++) {
    for (int j = 0; j < i; j++) {
      hcnt[i][H[j] - 'a']++;
    }
  }

  for (int i = 0; i <= H.size(); i++) {
    for (int j = 0; j < i; j++) {
      bool ok = true;
      for (int k = 0; k < 26; k++) {
        if (pcnt[k] == hcnt[i][k] - hcnt[j][k]) continue;
        ok = false;
      }
      if (ok == true) {
        cout << "YES" << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    check();
  }

  ////////////////////////////////
  return 0;
}
