#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
char alpha[21];
vector<int> ans;

int any_other(int n, int B, int E) { // in B, other than E
  int b0 = -1, b1 = -1;
  for (int i=0; i<n; i++) {
    if (!(B>>i & 1)) continue;
    if (E>>i & 1) b1 = i;
    else b0 = i;
  }
  if (b0 == -1) return E;
  return E ^ (1<<b0) ^ (1<<b1);
}

int any_bit(int n, int X) {
  for (int i=0; i<n; i++)
    if (X>>i & 1) return i;
  return n;
}

void enumerate(int n, int k, int B, int X, int S, int E) {
  // k: S, E popcount
  // B: alive bits
  // X: used bits
  // S, E: start, end bits
  if (S == E) {
    ans.push_back(X | S);
    return;
  }

  if (k == 1) {
    ans.push_back(X | S);
    for (int i=0; i<n; i++) {
      if ((B>>i & 1) && !(S>>i & 1) && !(E>>i & 1)) ans.push_back(X | 1<<i);
    }
    ans.push_back(X | E);
    return;
  }

  // a in S \ E
  int a = 0;
  for (a=0; a<n; a++) {
    if ((S>>a & 1) && !(E>>a & 1)) break;
  }

  // find mid
  int ME = any_other(n, B ^ 1<<a, E); // pick any mid
  int MS = ME ^ 1<<any_bit(n, ME); // remove one bit
  if ((S ^ 1<<a) == MS) MS = any_other(n, ME, MS); // if it collides with S, pick any other

  // recursion
  enumerate(n, k-1, B ^ 1<<a, X | 1<<a, S ^ 1<<a, MS); // use a
  enumerate(n, k, B ^ 1<<a, X, ME, E); // don't use a
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int n, k, S=0, E=0;
  string a, b;
  cin >> n >> k >> alpha >> a >> b;

  for (int i=0; i<k; i++) {
    S += 1 << (find(alpha, alpha+n, a[i]) - alpha);
    E += 1 << (find(alpha, alpha+n, b[i]) - alpha);
  }

  enumerate(n, k, (1<<n) - 1, 0, S, E);

  cout << ans.size() << endl;
  for (auto X: ans) {
    for (int i=0; i<n; i++) {
      if (X>>i & 1) cout << alpha[i];
    }
    cout << " ";
  }

  ////////////////////////////////
  return 0;
}
