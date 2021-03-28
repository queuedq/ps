#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 200005

int Z, N, A[MAX_N], coords[MAX_N];
int R[MAX_N];
int BIT[MAX_N];

void reset() {
  for (int i = 0; i < MAX_N; i++) {
    BIT[i] = 0;
  }
}

int query(int i) {
  int m = 0;
  while (i > 0) {
    m = max(BIT[i], m);
    i -= i & -i;
  }
  return m;
}

void update(int i, int val) {
  while (i < MAX_N) {
    BIT[i] = max(BIT[i], val);
    i += i & -i;
  }
}

int compress(int x) {
  return lower_bound(coords, coords + N, x) - coords + 1;
}

int calc() {
  // Input
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    coords[i] = A[i];
  }

  // Reset
  reset();

  // Compress
  sort(coords, coords + N);
  for (int i = 0; i < N; i++) {
    A[i] = compress(A[i]);
  }

  // Preprocess right sequence
  int prev = A[N - 1], length = 1;
  R[N - 1] = 1;
  for (int i = N - 2; i >= 0; i--) {
    if (A[i] < prev) {
      length++;
    } else {
      length = 1;
    }
    R[i] = length;
    prev = A[i];
  }

  // Process left sequence
  prev = -1, length = 0;
  int best = R[0];

  for (int i = 0; i < N - 1; i++) {
    if (A[i] > prev) {
      length++;
    } else {
      length = 1;
    }
    update(A[i], length);
    best = max(best, query(A[i + 1] - 1) + R[i + 1]);
    prev = A[i];
  }

  return best;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> Z;

  for (int i = 0; i < Z; i++) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
