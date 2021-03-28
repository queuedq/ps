#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
int N;
string S;
lld P[MAXN], cnt[MAXN];

lld bit(char c) {
  if ('a' <= c && c <= 'z') return 1LL << (c - 'a');
  if ('A' <= c && c <= 'Z') return 1LL << (c - 'A' + 26);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;

  lld ans = 0;
  for (int i=1; i<=N; i++) {
    P[i] = P[i-1] ^ bit(S[i-1]);
  }

  sort(P, P+N+1);
  cnt[0] = 1;

  for (int i=1; i<=N; i++) {
    int k = lower_bound(P, P+N+1, P[i]) - P;
    if (P[i] == P[k]) ans += cnt[k];
    for (int j=0; j<26*2; j++) {
      lld Q = P[i] ^ (1LL << j);
      int k = lower_bound(P, P+N+1, Q) - P;
      if (Q == P[k]) ans += cnt[k];
    }
    cnt[k]++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
