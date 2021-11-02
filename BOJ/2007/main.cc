#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[100], B[5000];

bool check(int a0) {
  A[0] = a0;
  multiset<int> S;
  for (int i=0; i<N*(N-1)/2; i++) S.insert(B[i]);

  for (int i=1; i<N; i++) {
    A[i] = *S.begin() - A[0];
    for (int j=0; j<i; j++) {
      if (S.count(A[i] + A[j]) == 0) return false;
      S.erase(S.find(A[i] + A[j]));
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*(N-1)/2; i++) cin >> B[i];
  sort(B, B + N*(N-1)/2);

  if (N == 2) {
    cout << min(B[0], 0) << " " << max(B[0], 0) << endl;
    return 0;
  }

  for (int t=2; t<=N-1; t++) {
    if ((B[0] + B[1] - B[t]) % 2 != 0) continue;
    int a0 = (B[0] + B[1] - B[t]) / 2;

    if (check(a0)) {
      for (int i=0; i<N; i++) cout << A[i] << " \n"[i == N-1];
      return 0;
    }
  }
  cout << "Impossible" << endl;

  ////////////////////////////////
  return 0;
}
