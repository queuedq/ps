#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;

struct Lecture {
  int num, s, e;
  bool operator <(const Lecture &L) const { return s < L.s; }
};

int N;
Lecture A[MN];
int ans[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].num >> A[i].s >> A[i].e;
  sort(A, A+N);

  int K = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq; // end time, room number
  vector<int> rooms; // available rooms

  for (int i=0; i<N; i++) {
    while (!pq.empty() && pq.top().first <= A[i].s) {
      auto [e, room] = pq.top(); pq.pop();
      rooms.push_back(room);
    }

    if (!rooms.empty()) {
      int room = rooms.back(); rooms.pop_back();
      ans[A[i].num] = room;
      pq.push({A[i].e, room});
    } else { // add new room
      ans[A[i].num] = ++K;
      pq.push({A[i].e, K});
    }
  }

  cout << K << endl;
  for (int i=1; i<=N; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
