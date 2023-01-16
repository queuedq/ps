#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3005;
int N, A[MN], B[MN], tmp[MN];

struct Cut { int t, a, b; };
vector<Cut> ans;

void cut(int a, int b) {
  for (int i=1; i<=N; i++) tmp[i] = B[i];
  int j = 1;
  for (int i=b+1; i<=N; i++, j++) B[j] = tmp[i];
  for (int i=a+1; i<=b; i++, j++) B[j] = tmp[i];
  for (int i=1; i<=a; i++, j++) B[j] = tmp[i];

  if ((a == 0 || a == N) && (b == 0 || b == N)) return;
  else if (a == 0 || a == b) ans.push_back({2, b});
  else if (b == N) ans.push_back({2, a});
  else ans.push_back({3, a, b});
}

int index(int x) {
  return find(B+1, B+N+1, x) - B;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    B[i] = i;
  }

  vector<int> order;
  for (int i=1, s=1, e=N-1; i<=N-1; i++) {
    if (i&1) order.push_back(A[e--]);
    else order.push_back(A[s++]);
  }
  reverse(order.begin(), order.end());

  bool L = !(N&1);
  if (L) cut(0, index(order[0])-1);
  else cut(0, index(order[0]));

  for (int i=1; i<N-1; i++) {
    if (L) cut(i, index(order[i]));
    else cut(index(order[i])-1, N-i);
    L = !L;
  }

  cout << ans.size() << endl;
  for (auto [t, a, b]: ans) {
    if (t == 2) cout << t << " " << a << endl;
    else cout << t << " " << a << " " << b << endl;
  }

  ////////////////////////////////
  return 0;
}
