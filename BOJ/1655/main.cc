#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  priority_queue<int> L;
  priority_queue<int, vector<int>, greater<int>> R;

  int mid = 0;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    if (a > mid) R.push(a);
    else L.push(a);

    while (L.size() < R.size()) { L.push(R.top()); R.pop(); }
    while (L.size() > R.size()+1) { R.push(L.top()); L.pop(); }
    assert(L.size() == R.size() || L.size() == R.size()+1);

    mid = L.top();
    cout << mid << endl;
  }

  ////////////////////////////////
  return 0;
}
