#include <bits/stdc++.h>

using namespace std;

struct Node {
    int cost, x, y;

    bool operator<(const Node &rhs) const {
        return cost < rhs.cost;
    }
    bool operator>(const Node &rhs) const {
        return cost > rhs.cost;
    }
};

int n, m, arr[1000][1000];
bool visit[1000][1000];

bool isValid(int x, int y) {
    if (x < 0 || y < 0)
        return false;
    if (x >= n || y >= m)
        return false;

    if (arr[x][y] == -1)
        return false;

    return !visit[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<Node, vector<Node>, greater<Node>> heap;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    heap.push({arr[0][0], 0, 0});

    while (!heap.empty()) {
        Node cur = heap.top();  heap.pop();

        int x = cur.x, y = cur.y;

        if (visit[x][y])
            continue;

        visit[x][y] = true;

        if (cur.x == n - 1 && cur.y == m - 1) {
            cout << cur.cost;
            return 0;
        }

        if (isValid(cur.x-1, cur.y))
            heap.push({cur.cost + arr[x-1][y], cur.x-1, cur.y});
        if (isValid(cur.x+1, cur.y))
            heap.push({cur.cost + arr[x+1][y], cur.x+1, cur.y});
        if (isValid(cur.x, cur.y-1))
            heap.push({cur.cost + arr[x][y-1], cur.x, cur.y-1});
        if (isValid(cur.x, cur.y+1))
            heap.push({cur.cost + arr[x][y+1], cur.x, cur.y+1});
    }

    cout << -1;
    
    return 0;
}