#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////

#define MAX_N 1000

lld T;
int N, M;
lld A[MAX_N], B[MAX_N];
lld S[MAX_N + 1], R[MAX_N + 1];
map<lld, lld> ASums, BSums;

void input() {
  cin >> T;

  cin >> N;
  lld sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
    S[i + 1] = sum;
  }

  cin >> M;
  sum = 0;
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    sum += B[i];
    R[i + 1] = sum;
  }
}

void calculateSums() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      ASums[S[j] - S[i]]++;
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j <= M; j++) {
      BSums[R[j] - R[i]]++;
    }
  }
}

lld count() {
  lld cnt = 0;
  for (auto it = ASums.begin(); it != ASums.end(); it++) {
    auto jt = BSums.find(T - it->first);
    if (jt != BSums.end()) {
      cnt += it->second * jt->second;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  calculateSums();
  cout << count() << endl;

  ////////////////////////////////
  return 0;
}
