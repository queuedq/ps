#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Node {
    Node *l, *r; int x;
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node *> pool(n);
    for (int i=0; i<n; i++) pool[i] = new Node();

    for (int i=0; i<n; i++) {
        pool[i]->x = i;
        if (i > 0) pool[i]->l = pool[i-1];
        if (i < n-1) pool[i]->r = pool[i+1];
    }

    Node *p = pool[k];
    stack<Node *> removed;

    for (auto query: cmd) {
        if (query[0] == 'D') {
            int X = stoi(query.substr(2));
            for (int i=0; i<X; i++) p = p->r;

        } else if (query[0] == 'U') {
            int X = stoi(query.substr(2));
            for (int i=0; i<X; i++) p = p->l;

        } else if (query[0] == 'C') {
            if (p->l != nullptr) p->l->r = p->r;
            if (p->r != nullptr) p->r->l = p->l;
            removed.push(p);

            if (p->r != nullptr) p = p->r;
            else p = p->l;

        } else if (query[0] == 'Z') {
            Node *q = removed.top(); removed.pop();
            if (q->l != nullptr) q->l->r = q;
            if (q->r != nullptr) q->r->l = q;
        }
    }

    string ans(n, 'O');
    while (!removed.empty()) {
        Node *q = removed.top(); removed.pop();
        ans[q->x] = 'X';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////
    
    int n = 8, k = 2;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    cout << solution(n, k, cmd) << endl;

    ////////////////////////////////
    return 0;
}
