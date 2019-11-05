#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<utility>
#include<functional>

using namespace std;

#define ioinit() ios::sync_with_stdio(false), cin.tie(nullptr)
#define x first
#define y second

typedef long long lld;
typedef pair<int, int> pii;

int N, M, Q;
pii A[100005];
vector<lld> B;
vector<pii> query[100005];

int main() {
    ioinit();
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        A[i] = {x, i};
    }
    sort(A+1, A+N+1);
    B.push_back(0);
    for (int i = 1; i <= N; i++)
        B.push_back(B[i-1] + A[i].y);
    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        if (K > N * (N+1) / 2) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }
        auto a = lower_bound(B.begin(), B.end(), K);
        int c = K - *(a-1);
        int b = distance(B.begin(), a);
        query[b].push_back()
    }
    return 0;
}