#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1000005;

int N, D[MAX_N], Q, K[MAX_N];

void insert(list<pii> *mono, int i, int a) {
  while (!mono->empty() && mono->back().second <= a) {
    mono->pop_back();
  }
  mono->push_back({i, a});
}

void roll(list<pii> *mono, int start) {
  if (mono->empty()) { return; }
  if (mono->front().first < start) { mono->pop_front(); }
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) { cin >> D[i]; }
  cin >> Q;
  for (int i = 0; i < Q; i++) { cin >> K[i]; }
}

int dp(int k) {
  int score = 0, result = 0;
  list<pii> *lessTired = new list<pii>();
  list<pii> *moreTired = new list<pii>();
  insert(lessTired, 0, D[0]);

  for (int i = 1; i < N; i++) {
    roll(lessTired, i - k);
    roll(moreTired, i - k);

    if (lessTired->empty()) {
      swap(lessTired, moreTired);
      score++;
    }

    if (lessTired->front().second > D[i]) {
      insert(lessTired, i, D[i]);
      if (i == N - 1) { result = score; }
    } else {
      insert(moreTired, i, D[i]);
      if (i == N - 1) { result = score + 1; }
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  for (int i = 0; i < Q; i++) {
    cout << dp(K[i]) << endl;
  }

  ////////////////////////////////
  return 0;
}
