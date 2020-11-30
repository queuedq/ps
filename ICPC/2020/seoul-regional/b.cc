#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int gcd(int a, int b) {
    while (b>0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0, a[6], b[6];

    for (int i = 0; i < 6; i++)
        cin >> a[i];
    for (int i = 0; i < 6; i++)
        cin >> b[i];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (a[i] > b[j])
                cnt++;

    // if (cnt == 0 || cnt == 36)

    cout << cnt / gcd(cnt, 36) << '/' << 36 / gcd(cnt, 36);

    return 0;
}