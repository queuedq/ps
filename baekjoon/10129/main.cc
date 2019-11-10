#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1000005;

int N, D[MAX_N], Q, K[MAX_N];

struct State {
  int i, height, score;
};

list<State> mono;

bool cmp(State a, State b) {
  if (a.score == b.score) { return a.height <= b.height; }
  return a.score > b.score;
}

void insert(list<State> &mono, State s) {
  while (!mono.empty() && cmp(mono.back(), s)) {
    mono.pop_back();
  }
  mono.push_back(s);
}

void roll(list<State> &mono, int start) {
  if (mono.empty()) { return; }
  if (mono.front().i < start) { mono.pop_front(); }
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) { cin >> D[i]; }
  cin >> Q;
  for (int i = 0; i < Q; i++) { cin >> K[i]; }
}

int dp(int k) {
  int result = 0;
  insert(mono, {0, D[0], 0});

  for (int i = 1; i < N; i++) {
    roll(mono, i - k);

    if (mono.front().height > D[i]) {
      insert(mono, {i, D[i], mono.front().score});
      if (i == N - 1) { result = mono.front().score; }
    } else {
      insert(mono, {i, D[i], mono.front().score + 1});
      if (i == N - 1) { result = mono.front().score + 1; }
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
