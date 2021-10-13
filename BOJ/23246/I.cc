#include<bits/stdc++.h>

#define endl "\n"

using namespace std;
using lld = long long;

int N;
vector<pair<pair<lld, lld>, lld>> P;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; i++) {
    lld b, p, q, r;
    cin >> b >> p >> q >> r;
    P.push_back({{p*q*r, p+q+r}, b});
  }

  sort(P.begin(), P.end());
  cout << P[0].second << ' ' << P[1].second << ' ' << P[2].second << endl;
  return 0;
}
