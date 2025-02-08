#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, H, M;

struct Grass { lld h, len; };
deque<Grass> L, R;
lld offset = 0, sum = 0;

void insert_front(deque<Grass> &D, lld h, lld len) {
  D.push_front({h - offset, len});
  sum += h * len;
}

void insert_back(deque<Grass> &D, lld h, lld len) {
  D.push_back({h - offset, len});
  sum += h * len;
}

lld erase_front(deque<Grass> &D, lld rem) {
  lld len = min(rem, D.front().len);
  sum -= (D.front().h + offset) * len;

  if (len < D.front().len) D.front().len -= len;
  else D.pop_front();
  return len;
}

lld erase_back(deque<Grass> &D, lld rem) {
  lld len = min(rem, D.back().len);
  sum -= (D.back().h + offset) * len;

  if (len < D.back().len) D.back().len -= len;
  else D.pop_back();
  return len;
}

void mow_left(int x) {
  int tot = 0;
  while (sz(L) && tot < x) tot += erase_front(L, x - tot);
  while (sz(R) && tot < x) tot += erase_front(R, x - tot);
  insert_front(L, 0, x);
}

void mow_right(int x) {
  int tot = 0;
  while (sz(R) && tot < x) tot += erase_back(R, x - tot);
  while (sz(L) && tot < x) tot += erase_back(L, x - tot);
  insert_back(R, 0, x);
}

void mow_all(int x) {
  int tot = 0;
  while (sz(L) && L.back().h + offset >= x) tot += erase_back(L, L.back().len);
  while (sz(R) && R.front().h + offset >= x) tot += erase_front(R, R.front().len);
  insert_back(L, x, tot);
}

void grow_all(int x) {
  offset += x;
  sum += N * x;
  mow_all(H);
}

// void debug() {
//   cout << "offset = " << offset << " sum = " << sum << endl;
//   for (auto [h, len]: L) cout << "(" << (h+offset) << "," << len << ") ";
//   for (auto [h, len]: R) cout << "(" << (h+offset) << "," << len << ") ";
//   cout << endl;
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> H >> M;
  L = {{0, N}}, R = {};

  for (int q=0; q<M; q++) {
    char c; int x = 0; cin >> c;
    if (c != 'Z') cin >> x;

    if (c == 'N') grow_all(x);
    if (c == 'L') mow_left(x);
    if (c == 'D') mow_right(x);
    if (c == 'S') mow_all(x);
    if (c == 'Z') cout << sum << endl;

    // debug();
  }

  ////////////////////////////////
  return 0;
}
