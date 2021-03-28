#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int INF = 1e9;
int N;
int P[1005];
int tot;
int D[1005][2][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> P[i];
        tot += P[i];
    }

    for (int i=0; i<N; i++) {
        for (int k=0; k<100; k++) {
            D[i][1][k] = P[i];
        }
    }

    for (int l=2; l<=N; l++) {
        int b = l%2;

        for (int i=0; i<N; i++) fill(D[i][b], D[i][b]+100, -INF);
        for (int i=0; i<N; i++) {
            int j = (i+l-1) % N;

            for (int k=0; k<100; k++) {
                if (k - P[i] >= 0) { // still me
                    D[i][b][k] = max(D[i][b][k], D[(i+1)%N][!b][k-P[i]] + P[i]);
                } else { // opponent
                    D[i][b][k] = max(D[i][b][k], P[i] - D[(i+1)%N][!b][P[i]-k-1]);
                }
                if (k - P[j] >= 0) { // still me
                    D[i][b][k] = max(D[i][b][k], D[i][!b][k-P[j]] + P[j]);
                } else { // opponent
                    D[i][b][k] = max(D[i][b][k], P[j] - D[i][!b][P[j]-k-1]);
                }
            }
        }
    }

    int rst = -INF;
    for (int i=0; i<N; i++)
        rst = max(rst, (tot + D[i][N%2][0]) / 2);

    cout << rst << endl;

    return 0;
}
