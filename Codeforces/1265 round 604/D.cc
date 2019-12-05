#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int a, b, c, d, bb, cc;
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> a >> b >> c >> d;

  if (a > b + 1 || d > c + 1) { cout << "NO" << endl; return 0; }
  if (a == b + 1) {
    if (c != 0 || d != 0) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    for (int i = 0; i < b; i++) {
      cout << "0 1 ";
    }
    cout << 0 << endl; return 0;
  }
  if (d == c + 1) {
    if (a != 0 || b != 0) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    for (int i = 0; i < c; i++) {
      cout << "3 2 ";
    }
    cout << 3 << endl; return 0;
  }

  bb = b - a; // >= 0
  cc = c - d;
  if (abs(bb - cc) > 1) { cout << "NO" << endl; return 0; }
  cout << "YES" << endl;

  if (bb > cc) {
    ans.push_back(1);
  }
  for (int i = 0; i < a; i++) {
    ans.push_back(0);
    ans.push_back(1);
  }
  for (int i = 0; i < min(bb, cc); i++) {
    ans.push_back(2);
    ans.push_back(1);
  }
  for (int i = 0; i < d; i++) {
    ans.push_back(2);
    ans.push_back(3);
  }
  if (bb < cc) {
    ans.push_back(2);
  }

  assert(ans.size() == a + b + c + d);
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[ans.size() - 1] << endl;

  ////////////////////////////////
  return 0;
}
