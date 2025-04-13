#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  cin >> N;

  for (int i=N+1; i<=9999; i++) {
    int a = i/100, b = i%100;
    if ((a+b)*(a+b) == i) { cout << i << endl; return 0; }
  }
  cout << -1 << endl;

  return 0;
}
