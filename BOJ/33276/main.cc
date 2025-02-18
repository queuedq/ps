#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main() {
  cin >> N;

  // Solution 1

  for (int i=1; i<=N-1; i++) {
    cout << "A " << i << " " << i << "\n";
    cout << "A " << i << " " << N << "\n";
  }

  cout << "Q " << N-1 << " ";
  for (int i=1; i<=N-1; i++) cout << i << " ";
  cout << endl;

  cin >> ans;
  cout << "! " << ans << endl;

  // Solution 2

  for (int i=1; i<=N; i++) {
    cout << "A " << i << " " << i << "\n";
    cout << "C " << i << " " << (1<<29) << "\n";
  }
  cout << "C " << N+1 << " " << (1<<30 | 1<<29) << "\n";

  cout << "Q " << N+1 << " ";
  for (int i=1; i<=N+1; i++) cout << i << " ";
  cout << endl;

  cin >> ans;
  cout << "! " << (ans ^ (1<<30 | 1<<29)) << endl;

  return 0;
}
