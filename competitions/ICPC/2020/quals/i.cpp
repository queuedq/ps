#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[10000];
    vector<int> res;

    cin >> n;

    n *= 2;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n/2; i++)
        res.push_back(arr[i] + arr[n - i - 1]);

    sort(res.begin(), res.end());

    cout << res.front();
    
    return 0;
}