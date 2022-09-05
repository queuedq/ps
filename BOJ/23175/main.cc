#include <iostream>
using namespace std;

int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  int m; cin >> m;
  for (int i=0; i<m; i++) {
    int b; cin >> b;
    for (int j=0; j<b-1; j++) {
      int t; cin >> t;
      i++;
    }
    cout << b << " ";
  }
  return 0;
}
