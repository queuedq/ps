#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_Q 100
#define MAX_N 100

int q;
int n;
ll s[MAX_N];

void input() {
  cin >> q;
}

void query() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n, greater<int>());
}

bool determine() {
  int sum = 0;
  bool success = false;
  for (int i = 0; i < n; i++) {
    if (s[i] > 2048) {
      continue;
    } else if (s[i] == 2048) {
      success = true;
      break;
    } else {
      sum += s[i];
      if (sum == 2048) {
        success = true;
        break;
      }
    }
  }
  return success;
}

int main() {
  input();

  for (int i = 0; i < q; i++) {
    query();
    bool possible = determine();
    if (possible) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
