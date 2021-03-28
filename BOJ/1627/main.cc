#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3005;
int N, A[MN], D[MN];

bool ok(int i) {
  for (int j = max(i-2, 1); j <= min(i+2, N); j++) {
    if (A[j]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string str; cin >> N >> str;
  for (int i=1; i<=N; i++) A[i] = str[i-1] == 'P';

  vector<int> win;

  // immediate win
  for (int i=1; i<=N; i++) {
    bool x = i-2 >= 1 && A[i-2] && A[i-1];
    bool y = i-1 >= 1 && i+1 < N && A[i-1] && A[i+1];
    bool z = i+2 <= N && A[i+1] && A[i+2];
    if (x|y|z) win.push_back(i);
  }

  if (win.size()) {
    cout << "WINNING\n";
    for (auto w: win) cout << w << " ";
    return 0;
  }

  // grundy number
  for (int i=1; i<=N; i++) {
    vector<int> S(N*2);

    for (int j=1; j<=i; j++) {
      int l = max(j-3, 0), r = max(i-j-2, 0);
      S[D[l] ^ D[r]] = 1;
    }
    for (int j=0; j<=i; j++) {
      if (!S[j]) { D[i] = j; break; }
    }
  }

  // simulate
  for (int i=1; i<=N; i++) {
    if (!ok(i)) continue;

    A[i] = 1;

    int g = 0, cnt = 0;
    for (int j=1; j<=N; j++) {
      if (ok(j)) cnt++;
      else { g ^= D[cnt]; cnt = 0; }
    }
    g ^= D[cnt];

    if (g == 0) win.push_back(i);
    A[i] = 0;
  }

  if (win.size()) {
    cout << "WINNING\n";
    for (auto w: win) cout << w << " ";
  } else {
    cout << "LOSING\n";
  }

  ////////////////////////////////
  return 0;
}
