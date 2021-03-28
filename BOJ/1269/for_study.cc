#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
unordered_map<int, bool> A; // x가 집합 안에 있다면 A[x] = true

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int a, b; cin >> a >> b; // 집합 A, B의 크기

  for (int i=0; i<a; i++) {
    int x; cin >> x;
    A[x] = true;
  }

  int cnt = 0; // 교집합 크기

  for (int i=0; i<b; i++) {
    int x; cin >> x;
    if (A[x]) cnt++; // B의 원소 x가 A에도 들어있다면 세어 준다
  }

  cout << a + b - cnt*2 << endl;

  ////////////////////////////////
  return 0;
}
