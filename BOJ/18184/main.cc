#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
  cin >> N >> K;
  cout << "YES" << endl;

  if (K == 1<<N) {
    for (int i=0; i<1<<N; i++) cout << i << " ";
    return 0;
  }

  for (int i=0; i<N; i++) {
    if (K>>i & 1) {
      for (int j = 1<<i; j < 2<<i; j++) cout << j << " ";
    }
  }
  return 0;
}
