#include <iostream>
using namespace std;

int main() {
  for (int i=1; i<=100; i++) {
    for (int j=1; j<=100; j++) {
      if (j == i) cout << 9900+i << " ";
      else if (j < i) cout << (i-1)*99 + j << " ";
      else cout << (i-1)*99 + j-1 << " ";
    }
    cout << "\n";
  }

  return 0;
}
