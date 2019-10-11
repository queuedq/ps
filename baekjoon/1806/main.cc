#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////

int N, A[100000];
lld S;

void input() {
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  int l = 0, r = 0;
  lld sum = 0;
  int length = INT_MAX;

  while (r <= N) {
    if (sum >= S) {
      length = min(r - l, length);
      sum -= A[l];
      l++;
    } else {
      sum += A[r];
      r++;
    }
  }

  if (length < INT_MAX) {
    cout << length << endl;
  } else {
    cout << 0;
  }

  ////////////////////////////////
  return 0;
}
