#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int n;
lld d[100001], p[100001], l[100001], s[100001], last = 1E9+1, cost = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> l[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> p[i] >> s[i];
    }
    for(int i = 1; i < n; i++) {
        if(last*l[i] > s[i]*l[i] + p[i]) {
            last = s[i];
            cost += last*l[i] + p[i];
        } else {
            cost += last*l[i];
        }
    }
    cout << cost;
    return 0;
}
