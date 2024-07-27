#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int N, K, num[10];
lld D[11][2][1<<10]; // pos, match, mask

int main() {
    cin >> N >> K;
    for (int i=0; N>0; i++, N/=10) num[i] = N%10;

    for (int i=0; i<=10; i++) {
        for (int b: {0, 1}) {
            for (int m=0; m<1<<10; m++) {
                D[i][b][m] = LLONG_MAX;
            }
        }
    }
    D[10][1][0] = 0;
    
    for (int i=10; i>=1; i--) {
        for (int b: {0, 1}) {
            for (int m=0; m<1<<10; m++) {
                lld &cur = D[i][b][m];
                if (D[i][b][m] == LLONG_MAX) continue;

                if (b) {
                    for (int d=num[i-1]; d<=9; d++) {
                        int mask = (m == 0 && d == 0) ? 0 : (m|1<<d); // handle leading zero
                        lld &nxt = D[i-1][d==num[i-1]][mask];
                        nxt = min(nxt, cur*10+d);
                    }
                } else {
                    for (int d=0; d<=9; d++) {
                        lld &nxt = D[i-1][b][m|1<<d];
                        nxt = min(nxt, cur*10+d);
                    }
                }
                
            }
        }
    }

    lld ans = LLONG_MAX;
    for (int m=0; m<1<<10; m++) {
        if (__builtin_popcount(m) != K) continue;
        ans = min(ans, D[0][0][m]);
    }
    cout << ans << endl;
    
    return 0;
}
