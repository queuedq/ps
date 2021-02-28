#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Point {
    int x, y;
    bool isCross;
    bool operator ==(Point p) const { return pii(x, y) == pii(p.x, p.y); }
    bool operator !=(Point p) const { return pii(x, y) != pii(p.x, p.y); }
};

lld dist(Point p, Point q) {
    return abs(p.x-q.x) + abs(p.y-q.y);
}

struct Line {
    bool isVertical = false;
    Point p, q;

    Line() {}

    Line(int a, int b, int c, int d): p{a, b, false}, q{c, d, false} {
        if (p.x == q.x)
            isVertical = true;
    }

    int getDir() {
        if (isVertical) {
            if (p.y < q.y) return 1;
            else return 3;
        } else {
            if (p.x < q.x) return 0;
            else return 2;
        }
    }
};


bool byx(Point a, Point b) {
    return a.x < b.x;
}
bool byy(Point a, Point b) {
    return a.y < b.y;
}

Point inter(Line a, Line b) {
    if (a.isVertical == b.isVertical)
        return {-1, -1, false};
    if (a.isVertical == true)
        swap(a, b);

    if ((a.p.x <= b.p.x && b.p.x <= a.q.x) || (a.q.x <= b.p.x && b.p.x <= a.p.x))
        if ((b.p.y <= a.p.y && a.p.y <= b.q.y) || (b.q.y <= a.p.y && a.p.y <= b.p.y))
            return {b.p.x, a.p.y, true};
    
    return {-1, -1, false};
}

int n, time_query, dir; // dir == 0:→ 1:↑ 2:← 3:↓ , +1 == 반시계
Point start;
Line lines[500];
vector<Point> points;

unordered_map<int, set<pii>> mx, my;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> time_query;

    for (int i = 0; i < n; i++) {           // 라인 양끝점 push
        int a, b, c, d; cin >> a >> b >> c >> d;
        lines[i] = Line(a, b, c, d);
        points.push_back(lines[i].p);
        points.push_back(lines[i].q);
    }
    start = lines[0].p;
    dir = lines[0].getDir();

    for (int i = 0; i < n; i++) {           // 교차점 push
        for (int j = 0; j < n; j++) {
            Point p = inter(lines[i], lines[j]);
            if (p.isCross) points.push_back(p);
        }
    }

    for (auto p: points) {
        mx[p.x].insert({p.y, p.isCross});
        my[p.y].insert({p.x, p.isCross});
    }
    
    Point p = start;
    lld t = 0;

    do {
        Point q;
        if (dir % 2 == 0) {
            auto it = my[p.y].lower_bound({p.x, 0});
            if (dir == 0) { it++; }
            else { it--; }
            q = {it->first, p.y, it->second};
        } else {
            auto it = mx[p.x].lower_bound({p.y, 0});
            if (dir == 1) { it++; }
            else { it--; }
            q = {p.x, it->first, it->second};
        }
        
        t += dist(p, q);
        if (t > time_query) {
            cout << q.x - dx[dir] * (t-time_query) << " " << q.y - dy[dir] * (t-time_query) << endl;
            return 0;
        }

        if (q.isCross) dir = (dir+1) % 4;
        else dir = (dir+2) % 4;
        
        p = q;
    } while (p != start);

    time_query %= t;
    t = 0;

    do {
        Point q;
        if (dir % 2 == 0) {
            auto it = my[p.y].lower_bound({p.x, 0});
            if (dir == 0) { it++; }
            else { it--; }
            q = {it->first, p.y, it->second};
        } else {
            auto it = mx[p.x].lower_bound({p.y, 0});
            if (dir == 1) { it++; }
            else { it--; }
            q = {p.x, it->first, it->second};
        }

        t += dist(p, q);
        if (t > time_query) {
            cout << q.x - dx[dir] * (t-time_query) << " " << q.y - dy[dir] * (t-time_query) << endl;
            return 0;
        }
        
        if (q.isCross) dir = (dir+1) % 4;
        else dir = (dir+2) % 4;
        
        p = q;
    } while (p != start);

    return 0;
}
