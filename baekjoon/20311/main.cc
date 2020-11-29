#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

const int MN = 300'001;
int N, K, A[MN];
pii c[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  for (int i=1; i<=K; i++) {
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c+1, c+K+1);

  if (c[K].first > (N+1)/2) {
    cout << -1 << endl;
    return 0;
  }

  int j = K;
  for (int i=1; i<=N; i+=2) {
    A[i] = c[j].second;
    c[j].first--;
    if (c[j].first == 0) j--;
  }
  for (int i=2; i<=N; i+=2) {
    A[i] = c[j].second;
    c[j].first--;
    if (c[j].first == 0) j--;
  }

  for (int i=1; i<=N; i++) cout << A[i] << " ";

  return 0;
}
