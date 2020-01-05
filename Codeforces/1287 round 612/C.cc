
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n;
int even, odd; // available numbers
vector<int> p;
vector<int> evenItv, oddItv;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  even = n / 2; odd = n - even;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] > 0) {
      if (p[i] % 2 == 0) even--;
      else odd--;
    }
  }

  if (even + odd == n) {
    if (n == 1) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  int l = 0, r = n-1;
  while (p[l] == 0) { l++; }
  while (p[r] == 0) { r--; }

  int cpx = 0, len = 0;
  bool lastEven = (p[l] % 2 == 0);
  for (int i = l+1; i <= r; i++) {
    if (p[i] == 0) {
      len++; continue;
    }
    bool currentEven = (p[i] % 2 == 0);
    if (lastEven ^ currentEven) { // different parity
      cpx++;
    } else if (len == 0) { // same parity from now on
      // do nothing
    } else if (currentEven) {
      evenItv.push_back(len);
    } else {
      oddItv.push_back(len);
    }

    lastEven = currentEven;
    len = 0;
  }

  sort(evenItv.begin(), evenItv.end());
  sort(oddItv.begin(), oddItv.end());

  for (int i = 0; i < evenItv.size(); i++) {
    if (even >= evenItv[i]) even -= evenItv[i];
    else cpx += 2;
  }

  for (int i = 0; i < oddItv.size(); i++) {
    if (odd >= oddItv[i]) odd -= oddItv[i];
    else cpx += 2;
  }

  if (p[l] % 2 == 0) {
    if (even >= l) even -= l;
    else cpx += 1;
  } else {
    if (odd >= l) odd -= l;
    else cpx += 1;
  }

  if (p[r] % 2 == 0) {
    if (even >= n-r-1) even -= n-r-1;
    else cpx += 1;
  } else {
    if (odd >= n-r-1) odd -= n-r-1;
    else cpx += 1;
  }

  cout << cpx << endl;

  ////////////////////////////////
  return 0;
}
