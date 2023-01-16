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
  for (int i=0; i<N; i++) tmp[i] = B[i];
  int j = 0;
  for (int i=b; i<N; i++, j++) B[j] = tmp[i];
  for (int i=a; i<b; i++, j++) B[j] = tmp[i];
  for (int i=0; i<a; i++, j++) B[j] = tmp[i];

  if ((a == 0 || a == N) && (b == 0 || b == N)) return;
  else if (a == 0 || a == b) ans.push_back({2, b});
  else if (b == N) ans.push_back({2, a});
  else ans.push_back({3, a, b});
}

int index(int arr[], int x) {
  return find(arr, arr+N, x) - arr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    B[i] = i+1;
  }

  for (int i=0; i<N-1; i++) {
    int k = index(A, B[0]);
    int b = index(B, A[(k-1+N) % N]) + 1;
    int a = 0;
    while (B[a] == A[k]) {
      a++;
      k = (k+1) % N;
    }
    cut(a, b);
  }

  cut(0, index(B, A[0]));

  cout << ans.size() << endl;
  for (auto [t, a, b]: ans) {
    if (t == 2) cout << t << " " << a << endl;
    else cout << t << " " << a << " " << b << endl;
  }

  ////////////////////////////////
  return 0;
}
