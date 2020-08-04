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
int D[1005][1005][105];

int nxt(int i) { return (i+1) % N; }
int prv(int i) { return (i+N-1) % N; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> P[i];
        tot += P[i];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            fill(D[i][j], D[i][j]+105, -INF);
        }
    }

    for (int i=0; i<N; i++) {
        for (int k=0; k<=100; k++) {
            D[i][i][k] = P[i];
        }
    }

    for (int l=2; l<=N; l++) {
        for (int i=0; i<N; i++) {
            int j = (i+l-1) % N;

            for (int k=0; k<=100; k++) {
                if (k - P[i] >= 0) { // still me
                    D[i][j][k] = max(D[i][j][k], D[nxt(i)][j][k-P[i]] + P[i]);
                } else { // opponent
                    D[i][j][k] = max(D[i][j][k], P[i] - D[nxt(i)][j][P[i]-k-1]);
                }
                if (k - P[j] >= 0) { // still me
                    D[i][j][k] = max(D[i][j][k], D[i][prv(j)][k-P[j]] + P[j]);
                } else { // opponent
                    D[i][j][k] = max(D[i][j][k], P[j] - D[i][prv(j)][P[j]-k-1]);
                }
            }
        }
    }

    int rst = -1000000;
    for (int i = 0; i < N; i++)
        rst = max(rst, (tot+D[i][prv(i)][0])/2);

    cout << rst << endl;

    return 0;
}
