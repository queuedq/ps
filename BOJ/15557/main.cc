#include <bits/stdc++.h>
#define endl "\n"
#define popcount __builtin_popcount
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int L, Q, A[1<<20], sub[1<<20], sup[1<<20], pop[1<<20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> Q;
  string S; cin >> S;
  for (int m=0; m<1<<L; m++) {
    A[m] = S[m]-'0';
    pop[m] = popcount(m);
  }

  for (int m=0; m<1<<L; m++) sub[m] = sup[m] = A[m];
  for (int i=1; i<=L; i++) {
    for (int m=0; m<1<<L; m++) {
      if (m>>(i-1) & 1) sub[m] += sub[m ^ 1<<(i-1)];
      if (~m>>(i-1) & 1) sup[m] += sup[m ^ 1<<(i-1)];
    }
  }

  for (int i=0; i<Q; i++) {
    string S; cin >> S;

    int zero = 0, one = 0, any = 0;
    for (int i=0; i<L; i++) {
      if (S[i] == '0') zero += 1<<(L-i-1);
      if (S[i] == '1') one += 1<<(L-i-1);
      if (S[i] == '?') any += 1<<(L-i-1);
    }

    lld ans = 0;

    if (pop[zero] <= L/3) {
      ans = sup[one];
      for (int m = zero; m > 0; m = (m-1) & zero) {
        if (pop[m] % 2) ans -= sup[m | one];
        else ans += sup[m | one];
      }

    } else if (pop[one] <= L/3) {
      ans = pop[one] % 2 ? -sub[any] : sub[any];
      for (int m = one; m > 0; m = (m-1) & one) {
        if (pop[one ^ m] % 2) ans -= sub[m | any];
        else ans += sub[m | any];
      }

    } else {
      ans = A[one];
      for (int m = any; m > 0; m = (m-1) & any) {
        ans += A[m | one];
      }
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
