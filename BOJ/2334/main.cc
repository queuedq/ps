#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

struct Point { lld x, y; };
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

////////////////////////////////////////////////////////////////
#define MAX_N 705

int T, N;
vector<Point> P;

void input() {
  cin >> N;
  for (int i=0; i<N; i++) {
    double x, y; cin >> x >> y;
    P.push_back({(lld)round(x * 100), (lld)round(y * 100)});
  }

  sort(P.begin(), P.end());
  N = unique(P.begin(), P.end()) - P.begin();
  P.resize(N);
}

bool calc() {
  for (int i=1; i<N; i++) {
    auto [dx, dy] = P[0] - P[i];

    vector<Point> Q(N); // Change of basis (& resize by 2 to only deal with integers)
    Point mid = P[0] + P[i];
    for (int j=0; j<N; j++) {
      Q[j] = 2*P[j] - mid;
      Q[j] = {dy*Q[j].x - dx*Q[j].y, dx*Q[j].x + dy*Q[j].y};
    }
    sort(Q.begin(), Q.end());

    vector<Point> st;
    bool onFold = false;
    for (int j=0; j<N; j++) {
      if (Q[j].y == 0) { onFold = true; break; }
      if (!st.empty() && st.back().x == Q[j].x && st.back().y == -Q[j].y) st.pop_back();
      else st.push_back(Q[j]);
    }

    if (!onFold && st.size() == 0) return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    input();
    cout << (calc() ? "YES" : "NO") << endl;
    P.clear();
  }

  ////////////////////////////////
  return 0;
}
