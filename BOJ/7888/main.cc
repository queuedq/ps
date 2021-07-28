#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, room[MN], L, R;

struct Lecture {
  int s, e, i;
  bool operator <(const Lecture &L) const { return s < L.s; }
} A[MN];

void solve() {
  cin >> N;

  for (int i=0; i<N; i++) {
    int s, e; cin >> s >> e;
    A[i] = {s, e, i};
  }
  sort(A, A+N);
  for (int i=0; i<N; i++) {
    if (A[i].i == 0) L = i;
    if (A[i].i == 1) R = i;
  }
  if (L > R) swap(L, R);

  // Count num of rooms
  priority_queue<pii, vector<pii>, greater<pii>> pq; // {end, _}
  for (int i=0; i<N; i++) {
    if (!pq.empty() && pq.top().first <= A[i].s) pq.pop();
    pq.push({A[i].e, 0});
  }
  int K = pq.size();
  if (K == 1) { cout << 2 << endl; return; }

  // Assign rooms
  pq = priority_queue<pii, vector<pii>, greater<pii>>(); // {end, room}
  for (int i=0; i<K; i++) { pq.push({-1, i}); }

  for (int i=0; i<=L; i++) {
    room[i] = pq.top().second; pq.pop();
    pq.push({A[i].e, room[i]});
  }

  int last = L; // last lecture same room as prof L
  bool fixed = true; // prof L's room = ... = prof R's room
  for (int i=L+1; i<=R; i++) {
    room[i] = pq.top().second; pq.pop();

    if (room[i] == room[L]) {
      // able to swap A[i-1] and A[i] / able to place A[i] elsewhere
      if (A[last].e <= A[i-1].s || pq.top().first <= A[i].s) {
        fixed = false;
        break;
      }
      last = i;
    }

    pq.push({A[i].e, room[i]});
  }

  if (room[L] == room[R] && fixed) cout << K+1 << endl;
  else cout << K << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
