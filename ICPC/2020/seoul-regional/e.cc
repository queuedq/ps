#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

    int n, a[1000000], sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > 1)
            break;
        a[i] = abs(a[i] - a[i - 1]);
        a[i - 1] = 0;
    }

    for (int i = 0; i < n; i++)
        sum += a[i];
    
    if (sum)
        cout << "NO";
    else
    {
        cout << "YES";
    }
    

    return 0;
}