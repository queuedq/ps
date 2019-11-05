#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

///////

struct Point {
  lld x, y;
};
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }
