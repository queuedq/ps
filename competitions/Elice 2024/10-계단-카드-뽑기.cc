#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int ST = 1<<16;
int N, A[ST];
int cnt[ST*2], seg[ST*2]; // given sorted array X, finds min(X[i] - i)

void add(int i, int v) {
    int n = i + ST;
    cnt[n] += v;
    if (cnt[n] > 0) seg[n] = i - cnt[n];
    else seg[n] = INF;

    for (n/=2; n>0; n/=2) {
        cnt[n] = cnt[n*2] + cnt[n*2+1];
        seg[n] = min(seg[n*2], seg[n*2+1] - cnt[n*2]);
    }
}

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=0; i<ST*2; i++) seg[i] = INF;

    int ans = 0;
    int i = 1;
    for (int j=1; j<=N; j++) {
        add(A[j], 1);
        while (i <= j && seg[1] < 0) add(A[i++], -1);
        ans = max(ans, j-i+1);
    }

    cout << ans << endl;
    return 0;
}
