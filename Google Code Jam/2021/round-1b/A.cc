#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld HM = 12;
const lld MM = 60;
const lld SM = 60LL * 1'000'000'000;

inline pll mod(lld a, lld b) {
  lld r = (a % b + b) % b;
  lld q = (a - r) / b;
  return {q, r};
}

struct Time {
  lld h, m, s; // s in nanoseconds
};

Time normalize(Time t) {
  auto [sq, sr] = mod(t.s, SM);
  auto [mq, mr] = mod(t.m + sq, MM);
  auto [hq, hr] = mod(t.h + mq, HM);
  return {hr, mr, sr};
}

Time solve(lld a, lld b, lld c) {
  // x : axis in ticks
  // a-x = 720 s
  // b-x = 12 SM m + 12 s
  // c-x = MM SM h + SM m + s
  // 12(c-x) = 12 MM SM h + 12 SM m + 12 s
  // 12(c-x) - (b-x) = 12 MM SM h
  // 12c - b - 11x = 12 MM SM h
  // 11x = 12c - b - 12 MM SM h
  // x = 12c - b - 12 MM SM h

  for (lld h = -12; h < 12; h++) {
    lld tmp;

    tmp = 12*c - b - 12*MM*SM*h;
    if (tmp % 11 != 0) continue;
    lld x = tmp / 11;
    
    tmp = a - x;
    if (tmp % 720 != 0) continue;
    lld s = tmp / 720;

    tmp = b - x - 12*s;
    if (tmp % (12*SM) != 0) continue;
    lld m = tmp / (12*SM);

    return normalize({h, m, s});
  }
  return {-1, -1, -1};
}

void print_time(int test, Time t) {
  cout << "Case #" << test << ": ";
  cout << t.h << " " << t.m << " " << t.s / (lld)1e9 << " " << t.s % (lld)1e9 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int test=1; test<=T; test++) {
    lld a, b, c; cin >> a >> b >> c;
    
    Time t;
    t = solve(a, b, c);
    if (t.h != -1) { print_time(test, t); continue; }
    t = solve(a, c, b);
    if (t.h != -1) { print_time(test, t); continue; }
    t = solve(b, a, c);
    if (t.h != -1) { print_time(test, t); continue; }
    t = solve(b, c, a);
    if (t.h != -1) { print_time(test, t); continue; }
    t = solve(c, a, b);
    if (t.h != -1) { print_time(test, t); continue; }
    t = solve(c, b, a);
    if (t.h != -1) { print_time(test, t); continue; }
  }

  ////////////////////////////////
  return 0;
}
