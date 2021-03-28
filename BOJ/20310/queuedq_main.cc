#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string S; cin >> S;
  int N = S.size();

  int zero = 0, one = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == '0') zero++;
    else one++;
  }
  
  vector<bool> mask(N);

  int cnt = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == '0') {
      mask[i] = true;
      cnt++;
    }
    if (cnt == zero/2) break;
  }

  cnt = 0;
  for (int i=N-1; i>=0; i--) {
    if (S[i] == '1') {
      mask[i] = true;
      cnt++;
    }
    if (cnt == one/2) break;
  }
  
  for (int i=0; i<N; i++) {
    if (mask[i]) cout << S[i];
  }

  return 0;
}
