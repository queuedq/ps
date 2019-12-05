#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 4e5 + 5;
int N, P[MAX_N];
int g, s, b;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
}

bool calc() {
  g = s = b = 0;
  while (g < N && P[g] == P[0]) { g++; }
  if (g > N / 2) { return false; }
  int ss = g * 2; s = ss;
  while (s < N && P[s] == P[ss]) { s++; }
  if (s > N / 2) { return false; }
  int bb = s + g; b = bb;
  while (b < N && P[b] == P[bb]) { b++; }
  if (b > N / 2) { return false; }

  int maxB = b;
  while (true) {
    maxB = b;
    while (b < N && P[b] == P[maxB]) { b++; }
    if (b > N / 2) { break; }
  }
  b = maxB;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i< T; i++) {
    input();
    if (calc()) {
      cout << g << " " << s - g << " " << b - s << endl;
    } else {
      cout << "0 0 0" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
