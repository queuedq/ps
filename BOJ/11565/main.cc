#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B; cin >> A >> B;
  int a = 0, b = 0;
  for (int i=0; i<A.size(); i++) a += A[i] == '1';
  for (int i=0; i<B.size(); i++) b += B[i] == '1';
  if (a%2) a++;
  cout << (b <= a ? "VICTORY" : "DEFEAT") << endl;
  return 0;
}
