#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  stack<int> S;
  for (int i=0; i<N; i++) {
    while (!S.empty() && A[S.top()] < A[i]) S.pop();
    if (S.empty()) cout << 0 << " ";
    else cout << S.top()+1 << " ";
    S.push(i);
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
