#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, A[MAXN];
priority_queue<int> D;
vector<int> B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  for (int i=0; i<N; i++) {
    D.push(A[i]-i);
    D.push(A[i]-i);
    B.push_back(D.top()+i);
    D.pop();
  }

  for (int i=N-2; i>=0; i--) B[i] = min(B[i], B[i+1]-1);

  for (int i=0; i<N; i++) cout << B[i] << endl;

  ////////////////////////////////
  return 0;
}
