#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MN = 35;
int N, A[MN];
map<vector<int>, int> D;

int dp(int i, const vector<int> &P) {
    if (D.count(P)) return D[P];
    if (i == N-1) return D[P] = 0;
    D[P] = INF;

    for (int a=0; a<P.size(); a++) {
        for (int b=a+1; b<P.size(); b++) {
            // next partition
            vector<int> Q = P;
            Q[a] += Q[b];
            swap(Q[b], Q.back());
            Q.pop_back();
            sort(Q.begin(), Q.end());

            D[P] = min(D[P], dp(i+1, Q) + A[i] * P[a] * P[b]);
        }
    }
    return D[P];
}

int main() {
    cin >> N;
    for (int i=0; i<N-1; i++) { cin >> A[i]; A[i] ^= 1; }
    
    cout << dp(0, vector<int>(N, 1)) << endl;
    return 0;
}
