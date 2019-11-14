#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int A[200005], last[200005], dist[200005];
int N;

void calc() {
  // Input
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  //Reset
  for (int i = 1; i <= N; i++) {
    last[i] = -1;
    dist[i] = INT_MAX;
  }

  // Calc
  if (N == 1) {
    cout << -1 << endl;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (last[A[i]] == -1) {
      last[A[i]] = i; continue;
    }
    int d = i - last[A[i]];
    dist[A[i]] = min(dist[A[i]], d);
    last[A[i]] = i;
  }

  int minDist = INT_MAX;
  for (int i = 1; i <= N; i++) {
    // cout << dist[i] << " ";
    if (dist[i] < minDist) {
      minDist = dist[i];
    }
  }

  if (minDist == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << minDist + 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T;
  cin >> T;
  for (int q = 0; q < T; q++) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
