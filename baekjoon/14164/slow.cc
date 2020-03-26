#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point { lld x, y; };
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

lld cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double length(Point a) { return sqrt(a * a); }
double angle(Point a, Point b) {
  double c = a * b / length(a) / length(b);
  double s = cross(a, b) / length(a) / length(b);
  return atan2(s, c);
}

struct Fenwick {
  vector<lld> arr;

  Fenwick(int size) { arr.resize(size); }

  lld query(int i) {
    i++;
    int s = 0;
    while (i > 0) { s += arr[i]; i -= i & -i; }
    return s;
  }

  void update(int i, int val) {
    i++;
    while (i < arr.size()) { arr[i] += val; i += i & -i; }
  }
};


template<class T>
ostream& operator << (ostream& os, pair<T, T> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<class T>
ostream& operator << (ostream& os, vector<T> vec) {
  os << "{";
  for (auto it = vec.begin(); it != vec.end()-1; it++) { cout << *it << ", "; }
  if (!vec.empty()) cout << *(vec.end()-1);
  os << "}";
  return os;
}

////////////////////////////////
const int MAXN = 305;
int N, ans[MAXN];
Point P[MAXN];

int compress(vector<double> & v, double x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
      vector<pair<double, double>> p1, p2;
      vector<double> angles;

      for (int k=0; k<N; k++) {
        if (k == i || k == j) continue;

        double th = angle(P[j]-P[i], P[k]-P[i]);
        double ph = angle(P[k]-P[j], P[i]-P[j]);
        if (th > 0) p1.push_back({th, ph});
        if (th < 0) p2.push_back({-th, -ph});
        angles.push_back(abs(ph));
      }

      sort(p1.begin(), p1.end());
      sort(p2.begin(), p2.end());
      sort(angles.begin(), angles.end());

      Fenwick bit1(N), bit2(N);

      for (auto p: p1) {
        double ph = compress(angles, p.second);
        ans[bit1.query(ph)]++;
        bit1.update(ph, 1);
      }

      for (auto p: p2) {
        double ph = compress(angles, p.second);
        ans[bit2.query(ph)]++;
        bit2.update(ph, 1);
      }
    }
  }

  for (int i=0; i<N-2; i++) {
    cout << ans[i] / 3 << endl;
  }

  ////////////////////////////////
  return 0;
}
