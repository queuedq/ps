#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

const int MN = 300'001;
int N, K, A[MN], c[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  for (int i=0; i<K; i++) cin >> c[i];

  if (c[0] > (N+1)/2) {
    cout << -1 << endl;
    return 0;
  }

  for (int i=0; i<c[0]; i++) A[i*2] = 1;

  int j = 2;
  for (int i=0; i<N; i++) {
    if (A[i] == 1) continue;
    A[i] = j++;
  }

  for (int i=0; i<N; i++) cout << A[i] << " ";

  return 0;
}
