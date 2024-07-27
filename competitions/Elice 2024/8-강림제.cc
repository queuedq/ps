#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MX = 305;
int N, M, K, T;
int cnt[MX];
int D[MX][MX][MX]; // t, used, alive -> max time

int main() {
    cin >> N >> M >> K >> T;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        for (int t=a; t<b; t++) cnt[t]++;
    }

    for (int t=1; t<=N+1; t++) {
        for (int k=0; k<=K; k++) {
            for (int a=0; a<=k; a++) {
                if (cnt[t] < T) {
                    D[t][k][a] = max(D[t-1][k-a][0], D[t-1][k][a]);
                    D[t][k][a] += (cnt[t]+a >= T);
                } else {
                    D[t][k][a] = -INF;
                    D[t][k][0] = max(D[t][k][0], D[t-1][k][a] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int a=0; a<=K; a++) ans = max(ans, D[N][K][a]);
    cout << ans << endl;
    return 0;
}
