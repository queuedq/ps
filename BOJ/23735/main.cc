#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int len, N, border[MN];

struct Point {
  int x, y, c;
  bool operator <(const Point &P) const { return pii(x, y) < pii(P.x, P.y); }
};
Point P[MN];
vector<Point> D, R, U, L;
vector<int> st;

void push(int c) {
  if (!st.empty() && st.back() == c) st.pop_back();
  else st.push_back(c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> len >> N;
  for (int i=0; i<N; i++) {
    int x, y, c; cin >> x >> y >> c;
    P[i] = {x, y, c};
    if (x == 0 || x == len || y == 0 || y == len) border[c]++;
    
    if (y == 0) D.push_back(P[i]);
    else if (x == len) R.push_back(P[i]);
    else if (y == len) U.push_back(P[i]);
    else if (x == 0) L.push_back(P[i]);
  }

  sort(all(D));
  sort(all(R));
  sort(all(U));
  reverse(all(U));
  sort(all(L));
  reverse(all(L));
  
  for (auto [x, y, c]: D) if (border[c] == 2) push(c);
  for (auto [x, y, c]: R) if (border[c] == 2) push(c);
  for (auto [x, y, c]: U) if (border[c] == 2) push(c);
  for (auto [x, y, c]: L) if (border[c] == 2) push(c);

  cout << (st.size() == 0) << "%" << endl;

  ////////////////////////////////
  return 0;
}
