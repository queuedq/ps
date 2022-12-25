#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101;
int N, A[MN];
int R, mat[MN], use[MN];

void gray(int i) {
  if (i < 0) return;
  gray(i-1);
  cout << use[i] << endl;
  gray(i-1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  for (int i=0; i<N; i++) {
    // check if A[i] is independent
    int x = A[i];
    for (int j=0; j<R; j++) {
      if ((x ^ mat[j]) < x) x ^= mat[j];
    }

    // add A[i] if independent
    if (x != 0) {
      use[R] = i+1;
      mat[R] = x;
      R++;
    }
  }

  cout << (1<<R)-1 << endl;
  gray(R-1);

  ////////////////////////////////
  return 0;
}
