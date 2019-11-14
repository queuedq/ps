#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;

int c, m, x;

void input() {
  cin >> c;
  cin >> m;
  cin >> x;
}

int main() {
  cin >> q;

  for (int i = 0; i < q; i++) {
    input();
    int teams = min({c, m, (c + m + x) / 3});
    printf("%d\n", teams);
  }

  return 0;
}
