#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

bool v[505];
int match[505];
int ans[505][505];
bool a[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) cin >> a[i][j];
        ans[i+1][i+1] = 1;
    }

    for (int j=0; j<n; j++)
    {
        bool check = 0;
        for (int i=0; i<n; i++){
            if (v[i]) continue;
            if(!a[i][j]) continue;
            else
            {
                check = 1;
                v[i] = 1;
                match[j+1] = i+1;
                for (int k=0; k<n; k++)
                {
                    if (k==i) continue;
                    if (a[k][j])
                    {
                        for (int x=0; x<n; x++) a[k][x] ^= a[i][x];
                        for (int x=1; x<=n; x++)
                        {
                            if(ans[i+1][x]%2) ans[k+1][x]++;
                        }
                    }
                }

                break;
            }
        }
        if (!check)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (ans[match[i]][j]%2) cout << j << " "; 
        }
        cout << "\n";
    }

    return 0;
}