#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void input() {
  cin >> n;
}

int main() {
  input();

  for (int i = 0; i < n; i++) {
    string line = "";
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        line += 'W';
      } else {
        line += 'B';
      }
    }
    cout << line << endl;
  }

  return 0;
}
