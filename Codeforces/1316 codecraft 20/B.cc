#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n;
string s;
pair<string, int> arr[5005];

string reverse(string str) {
  reverse(str.begin(), str.end());
  return str;
}

string modify(string str, int k) {
  if ((n-k+1) % 2 == 0) {
    return str.substr(k-1, n) + str.substr(0, k-1);
  } else {
    return str.substr(k-1, n) + reverse(str.substr(0, k-1));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int k = 1; k <= n; k++) {
      arr[k] = {modify(s, k), k};
    }
    sort(arr+1, arr+n+1);
    cout<<arr[1].first<<endl<<arr[1].second<<endl;
  }

  ////////////////////////////////
  return 0;
}
