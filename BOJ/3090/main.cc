#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, T, A[MN], B[MN];

bool ok(int d) {
  copy(A, A+N, B);
  for (int i=1; i<N; i++) B[i] = min(B[i], B[i-1]+d);
  for (int i=N-2; i>=0; i--) B[i] = min(B[i], B[i+1]+d);

  lld sum = 0;
  for (int i=0; i<N; i++) sum += A[i] - B[i];
  return sum <= T;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> T;
  for (int i=0; i<N; i++) cin >> A[i];

  int l=-1, r=1e9;
  while (l+1 < r) {
    int mid = (l+r)/2;
    if (ok(mid)) r = mid;
    else l = mid;
  }

  for (int i=1; i<N; i++) A[i] = min(A[i], A[i-1]+r);
  for (int i=N-2; i>=0; i--) A[i] = min(A[i], A[i+1]+r);
  for (int i=0; i<N; i++) cout << A[i] << " ";

  ////////////////////////////////
  return 0;
}
