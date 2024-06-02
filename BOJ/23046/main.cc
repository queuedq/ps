#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MQ = 2e6 + 100;
string T;
int Q, cnt[MQ]; // digit queries
int sum[MQ];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> T; Q = sz(T);
  
  cnt[0] = T[0] != '-';
  for (int i=0; i<Q; i++) cnt[i] = cnt[i-1] + (T[i] != '-');

  int L=0, R=0; // # of future digit queries
  for (int i=Q-1; i>=0; i--) {
    if (T[i] == '-') { swap(L, R); continue; }

    int d = T[i]-'0';
    sum[0] += d;
    sum[++R] -= d;
    sum[cnt[i]] += d;
    sum[cnt[i]+L] -= d;
  }

  // sweep
  for (int i=1; i<=Q; i++) sum[i] += sum[i-1];

  // carry
  for (int i=0; i<Q+50; i++) {
    sum[i+1] += sum[i] / 10;
    sum[i] %= 10;
  }

  // print
  bool leading_zero = 1;
  for (int i=Q+50; i>=0; i--) {
    if (leading_zero && sum[i] == 0) continue;
    leading_zero = 0;
    cout << sum[i];
  }

  ////////////////////////////////
  return 0;
}
