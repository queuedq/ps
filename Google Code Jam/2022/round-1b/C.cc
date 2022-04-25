#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int pcnt;

void query(string S) {
  cout << S << endl;
  cin >> pcnt;
  if (pcnt == 8) {
    cout << "11111111" << endl;
    cin >> pcnt;
  }
}

void make_even() {
  query("00000000");
  if (pcnt == 0) return;
  if (pcnt % 2) query("10000000");
}

void solve_four() { // 0x0x0x0x, 1x1x1x1x
  auto check = [&]() {
    int tmp = pcnt;
    query("10101010");
    if (pcnt == 0 || pcnt == (tmp^4) || pcnt == ((8-tmp)^4)) return true;
    return false;
  };

  query("11001100"); if (pcnt == 0) return; if (check()) return;
  query("11110000"); if (pcnt == 0) return; if (check()) return;
  query("11001100"); if (pcnt == 0) return; if (check()) return;
  query("11000000"); if (pcnt == 0) return; if (check()) return;
  query("11001100"); if (pcnt == 0) return; if (check()) return;
  query("11110000"); if (pcnt == 0) return; if (check()) return;
  query("11001100"); if (pcnt == 0) return; if (check()) return;
}

void solve_10101010() {
  query("10101010"); if (pcnt == 0) return;
}

void solve_11001100() {
  query("11001100"); if (pcnt == 0) return;
  solve_10101010(); if (pcnt == 0) return;
}

void solve_10001000() {
  query("10001000"); if (pcnt == 0) return;
  solve_10101010(); if (pcnt == 0) return;
  solve_11001100(); if (pcnt == 0) return;
}

void solve_11110000() { // 11110000, 10110100
  query("11110000"); if (pcnt == 0) return;
  solve_10101010(); if (pcnt == 0) return;
  solve_11001100(); if (pcnt == 0) return;
  solve_10001000(); if (pcnt == 0) return;
}

void solve_10100000() { // 10100000, 11011000
  query("10100000"); if (pcnt == 0) return;
  solve_10101010(); if (pcnt == 0) return;
  solve_11001100(); if (pcnt == 0) return;
  solve_10001000(); if (pcnt == 0) return;
  solve_11110000(); if (pcnt == 0) return;
}

void solve_11000000() { // 11000000, 10010000, ...
  query("11000000"); if (pcnt == 0) return;
  solve_10101010(); if (pcnt == 0) return;
  solve_11001100(); if (pcnt == 0) return;
  solve_10001000(); if (pcnt == 0) return;
  solve_11110000(); if (pcnt == 0) return;
  solve_10100000(); if (pcnt == 0) return;
}

void solve_other_four() {
  solve_10101010(); if (pcnt == 0) return;
  solve_10001000(); if (pcnt == 0) return;
  solve_10100000(); if (pcnt == 0) return;
  solve_11000000(); if (pcnt == 0) return;
}

void solve() {
  make_even(); if (pcnt == 0) return;
  solve_four(); if (pcnt == 0) return;
  solve_other_four(); if (pcnt == 0) return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
    if (pcnt == -1) return 0;
  }

  ////////////////////////////////
  return 0;
}
