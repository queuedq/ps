#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 100005
lld N, A[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A + N);

  lld a = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (i < N / 2) {
      a += A[i];
    } else {
      b += A[i];
    }
  }

  cout << a * a + b * b << endl;

  ////////////////////////////////
  return 0;
}
