#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int N, a, b;
string S, T;
char sa, sb;
bool D[MAXN][3];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>S>>T>>a>>b;
    sa = S[a]; sb = S[b];
    S = S.substr(0,a) + S.substr(a+1, b-a-1) + S.substr(b+1, N-b-1) + "aa";
    
    D[0][0] = true;

    for (int i=1; i<=N; i++) {
        D[i][0] = D[i-1][0] && S[i-1] == T[i-1];

        D[i][1] = D[i-1][0] && sa == T[i-1];
        D[i][1] = D[i][1] || (D[i-1][1] && S[i-2] == T[i-1]);
        
        D[i][2] = D[i-1][1] && sb == T[i-1];
        D[i][2] = D[i][2] || (D[i-1][2] && S[i-3] == T[i-1]);
    }

    if (D[N][2]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}