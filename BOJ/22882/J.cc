#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

const ll MX = 25;
ll N, K, A[MX][MX], ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct Node { ll x, y, d, e; }; // d: last X, e: last O

vector<ll> DK[MX], DK1[MX]; // DK: max(d, e) <= K, DK1: max(d, e) <= K-1

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cin >> A[i][j];
    }
    if (N == 1) {
        if (A[0][0] == K) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    // first
    queue<Node> Q;
    Q.push((Node){0, 0, LLONG_MIN, A[0][0]});
    
    while (!Q.empty()) {
        auto [x, y, d, e] = Q.front();
        if (x+y == N-1) break;
        Q.pop();

        for (int i: {0, 1}) {
            int xx = x+dx[i], yy = y+dy[i];
            Q.push((Node){xx, yy, max(d, e), max(e + A[xx][yy], A[xx][yy])});
        }
    }

    while (!Q.empty()) {
        auto [x, y, d, e] = Q.front();
        Q.pop();
        if (max(d, e) <= K) DK[x].push_back(e);
        if (max(d, e) <= K-1) DK1[x].push_back(e);
    }

    for (int x=0; x<N; x++) {
        sort(DK[x].begin(), DK[x].end());
        sort(DK1[x].begin(), DK1[x].end());
    }

    // second
    Q.push((Node){N-1, N-1, LLONG_MIN, A[N-1][N-1]});

    while (!Q.empty()) {
        auto [x, y, d, e] = Q.front();
        if (x+y == N) break;
        Q.pop();

        for (int i: {2, 3}) {
            int xx = x+dx[i], yy = y+dy[i];
            Q.push((Node){xx, yy, max(d, e), max(e + A[xx][yy], A[xx][yy])});
        }
    }

    while (!Q.empty()) {
        auto [x, y, d, e] = Q.front();
        Q.pop();

        if (max(d, e) <= K) {
            ans += upper_bound(DK[x].begin(), DK[x].end(), K-e) - DK[x].begin();
            ans += upper_bound(DK[x-1].begin(), DK[x-1].end(), K-e) - DK[x-1].begin();
        }
        if (max(d, e) <= K-1) {
            ans -= upper_bound(DK1[x].begin(), DK1[x].end(), K-1-e) - DK1[x].begin();
            ans -= upper_bound(DK1[x-1].begin(), DK1[x-1].end(), K-1-e) - DK1[x-1].begin();
        }
    }

    cout << ans << endl;
    return 0; 
}
