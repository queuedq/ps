#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 500
int N, brackets[MAX_N];

int swap(int l, int r, int x) {
  if (x == l) return r;
  if (x == r) return l;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  string raw;
  cin >> raw;
  int i = 0, correctness = 0;
  for (auto c: raw) {
    if (c == '(') {
      brackets[i] = 1;
      correctness++;
    } else {
      brackets[i] = 0;
      correctness--;
    }
    i++;
  }

  if (correctness != 0) {
    cout << "0\n1 1" << endl;
    return 0;
  }

  int best = 0, bestL = 0, bestR = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      int min = 0;
      int minCnt = 0;
      int open = 0;
      for (int x = 0; x < N; x++) {
        if (open == min) {
          minCnt++;
        } else if (open < min) {
          min = open;
          minCnt = 1;
        }

        if (brackets[swap(i, j, x)] == 1) { open++; }
        else { open--; }
      }

      if (minCnt > best) {
        best = minCnt;
        bestL = i;
        bestR = j;
      }
    }
  }

  cout << best << endl;
  cout << bestL + 1 << " " << bestR + 1 << endl;

  ////////////////////////////////
  return 0;
}
