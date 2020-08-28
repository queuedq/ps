#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXP = 1e5+5;
int pi[MAXP];
lld fib[105], D[105];
string sfib[105];

lld count(string S, string P) {
  int s = S.size(), p = P.size();
  lld ans = 0;

  int j = 0;
  for (int i=1; i<p; i++) {
    while (j > 0 && P[i] != P[j]) j = pi[j-1];
    if (P[i] == P[j]) pi[i] = ++j;
    else pi[i] = 0;
  }

  j = 0;
  for (int i=0; i<s; i++) {
    while (j > 0 && S[i] != P[j]) {
      j = pi[j-1];
    }
    if (S[i] == P[j]) {
      if (j == p-1) {
        ans++;
        j = pi[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

lld solve(int N, string P) {
  int p = P.size();

  D[0] = D[1] = 0;
  if (P == "0") D[0] = 1;
  if (P == "1") D[1] = 1;

  for (int i=2; i<=N; i++) {
    if (fib[i] < p) { D[i] = 0; continue; }

    string L = sfib[i-1];
    if (fib[i-1] > p-1) L = L.substr(fib[i-1]-(p-1), p-1);
    string R = sfib[i-2];
    if (fib[i-2] > p-1) R = R.substr(0, p-1);

    D[i] = D[i-1] + D[i-2] + count(L+R, P);
  }

  return D[N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fib[0] = 1, fib[1] = 1;
  sfib[0] = "0", sfib[1] = "1";
  int i;
  for (i=2; i<=100; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    sfib[i] = sfib[i-1] + sfib[i-2];
    if (fib[i] > MAXP*2) break;
  }
  for (; i<=100; i++) {
    fib[i] = fib[i-2];
    sfib[i] = sfib[i-2];
  }

  for (int t=1; ; t++) {
    int N; string P;
    cin >> N >> P;
    if (cin.eof()) break;
    cout << "Case " << t << ": " << solve(N, P) << endl;
  }

  ////////////////////////////////
  return 0;
}
