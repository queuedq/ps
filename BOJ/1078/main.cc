#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld D, digits, m[20];
vector<vector<lld>> cand;

lld pow(lld e) {
  lld res = 1;
  while (e--) res *= 10;
  return res;
}

void find(lld s, lld i, vector<lld> a) {
  if (i >= digits/2) return;
  lld cnt = 0;
  while (cnt < 10 && s < D) { s += m[i]; cnt++; }
  while (cnt >= -10 && s > D) { s -= m[i]; cnt--; }
  // s is maximal in range <= D

  if (cnt > 9 || cnt+1 < -9) return;
  if (s == D) {
    a.push_back(cnt);
    cand.push_back(a);
    return;
  }

  if (cnt <= 9 && cnt >= -9) {
    a.push_back(cnt);
    find(s, i+1, a);
    a.pop_back();
  }
  s += m[i];
  cnt++;
  if (cnt <= 9 && cnt >= -9) {
    a.push_back(cnt);
    find(s, i+1, a);
    a.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> D;

  for (digits = 2; digits <= 12; digits++) {
    for (lld i = 0; i < digits/2; i++) {
      m[i] = pow(digits-i-1) - pow(i);
    }
    find(0, 0, {});
    if (cand.size() > 0) break;
  }

  lld ans = LLONG_MAX;
  for (auto c: cand) {
    lld val = 0;
    for (lld i = 0; i < c.size(); i++) {
      if (c[i] > 0) val += c[i] * pow(digits-i-1);
      else if (c[i] < 0) val += -c[i] * pow(i);
      else if (i == 0) val += pow(digits-i-1) + pow(i);
    }
    ans = min(val, ans);
  }
  cout << (ans == LLONG_MAX ? -1 : ans) << endl;

  ////////////////////////////////
  return 0;
}
