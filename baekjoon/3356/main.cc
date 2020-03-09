#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1'000'005;
int N;
string S;
int lps[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  int len = 0;
  for (int i=1; i<N; i++) {
    while (len > 0 && S[i] != S[len]) len = lps[len-1];
    if (S[i] == S[len]) lps[i] = ++len;
    else lps[i] = 0;
  }

  cout << N - lps[N-1] << endl;

  ////////////////////////////////
  return 0;
}
