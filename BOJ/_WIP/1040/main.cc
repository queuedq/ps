#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, K, used, cnt[10], ans[19];
string N;

int find_used(int d) {
  while (d <= 9 && cnt[d] == 0) d++;
  return d;
}

int find_unused(int d) {
  while (d <= 9 && cnt[d] > 0) d++;
  return d;
}

void use(int i, int d) {
  ans[i] = d;
  if (cnt[d]++ == 0) used++;
}

void unuse(int d) {
  if (--cnt[d] == 0) used--;
}

bool solve_big(int i) { // already bigger than N, can fill any digits
  if (n-i < K-used) return false;

  int d = 0;
  if (used == K) d = find_used(d);

  for (; n-i > K-used; i++) use(i, d);
  assert(n-i == K-used);

  for (; i<n; i++) {
    d = find_unused(d);
    use(i, d);
  }
  assert(used == K);

  return true;
}

bool solve(int i) { // # of digits is same as N
  if (i == n) return used == K;

  // same
  int d = N[i] - '0';

  if (used < K || cnt[d] > 0) {
    use(i, d);
    if (solve(i+1)) return true;
    unuse(d);
  }
  
  // bigger
  d++;
  if (used == K) d = find_used(d);
  if (d == 10) return false;

  use(i, d);
  if (solve_big(i+1)) return true;
  unuse(d);

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  n = N.size();
  bool found = solve(0);
  
  if (found) {
    for (int i=0; i<n; i++) cout << ans[i];
  } else if (K > n) {
    cout << 10;
    for (int i=2; i<K; i++) cout << i;
  } else {
    cout << 1;
    for (int i=0; i<n-K+2; i++) cout << 0;
    for (int i=2; i<K; i++) cout << i;
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
