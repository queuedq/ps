#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
char I[100], O[100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << ":" << endl;

    int N; cin >> N;

    for (int i=0; i<N; i++) cin >> I[i];
    for (int i=0; i<N; i++) cin >> O[i];

    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (i == j) cout << 'Y';
        else if (i < j) {
          bool ok = true;
          for (int k=i; k<j; k++) {
            if (O[k] == 'N' || I[k+1] == 'N') ok = false;
          }
          if (ok) cout << 'Y';
          else cout << 'N';
        } else {
          bool ok = true;
          for (int k=i; k>j; k--) {
            if (O[k] == 'N' || I[k-1] == 'N') ok = false;
          }
          if (ok) cout << 'Y';
          else cout << 'N';
        }
      }
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
