#include <iostream>
using namespace std;

const int MN = 300'001;
int N, A[MN];

int main() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  bool ok = true;
  for (int i=1; i<=N; i++) {
    if (i%2 == 1 && A[i]%2 == 0) ok = false;
    if (i%2 == 0 && A[i]%2 == 1) ok = false;
  }

  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
