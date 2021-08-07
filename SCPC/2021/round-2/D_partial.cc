#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e6+5;
int N, M, K, last[26], ls[MN], lp[MN], pi[MN];
string S, P;

lld match() {
  fill(last, last+26, -1);
  for (int i=0; i<M; i++) {
    lp[i] = last[P[i]-'a'];
    last[P[i]-'a'] = i;
  }

  int j = 0;
  for (int i=1; i<M; i++) {
    while (j > 0) {
      if ((lp[j] == -1 && i-lp[i] > j) ||
          (lp[j] != -1 && j-lp[j] == i-lp[i])) break;
      j = pi[j-1];
    }
    if ((lp[j] == -1 && i-lp[i] > j) ||
        (lp[j] != -1 && j-lp[j] == i-lp[i])) {
      pi[i] = ++j;
    }
    else pi[i] = 0;
  }

  int ans = 0;
  j = 0;
  for (int i=0; i<N; i++) {
    while (j > 0) {
      if ((lp[j] == -1 && i-ls[i] > j) ||
          (lp[j] != -1 && j-lp[j] == i-ls[i])) break;
      j = pi[j-1];
    }
    if ((lp[j] == -1 && i-ls[i] > j) ||
        (lp[j] != -1 && j-lp[j] == i-ls[i])) {
      if (j == M-1) {
        ans++;
        j = pi[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

void solve(int test) {
  cin >> N >> K >> S;

  if (N * K > 1e7) {
    cout << "Case #" << test << endl;
    cout << 0 << endl;
    return;
  }
  
  fill(last, last+26, -1);
  for (int i=0; i<N; i++) {
    ls[i] = last[S[i]-'a'];
    last[S[i]-'a'] = i;
  }

  lld ans = 0;
  for (int i=1; i<=K; i++) {
    cin >> P;
    M = P.size();
    ans += match() * i;
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
