#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////

int N, M, seed;

int randAB(int a, int b) {
  assert(a <= b);
  return rand() % (b - a + 1) + a;
}

int main() {
  ////////////////////////////////

  // Usage: N M seed
  cin >> N >> M >> seed;

  srand(seed);

  cout << N << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << randAB(0, 1) * 2 - 1 << " ";
  }
  cout << randAB(0, 1) * 2 - 1 << endl;

  cout << M << endl;
  for (int i = 0; i < M; i++) {
    int a = randAB(1, N);
    int b = randAB(1, N);
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }
    cout << a << " " << b << endl;
  }

  ////////////////////////////////
  return 0;
}
