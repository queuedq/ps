#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K, C, A[500][6];

struct Space { // fractured search space
  int score;
  vector<int> team, vst; // team: partial team / vst: excluded
  bool operator <(const Space &S) const { return score < S.score; }
};

int score(const vector<int> &team) {
  vector<int> S(K);
  for (auto i: team) {
    for (int j=0; j<K; j++) S[j] = max(S[j], A[i][j]);
  }
  return accumulate(all(S), 0);
}

vector<int> best_team(const Space &S) {
  vector<int> team = S.team;

  for (int j=team.size(); j<K; j++) {
    pii mx = {-1, -1};
    for (int i=0; i<N; i++) {
      if (!S.vst[i] && !count(all(team), i))
        mx = max(mx, {A[i][j], i});
    }
    if (mx.second == -1) return {}; // no available members
    team.push_back(mx.second);
  }

  return team;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> C;
  for (int i=0; i<N; i++) {
    for (int j=0; j<K; j++) cin >> A[i][j];
  }

  Space init = {0, {}, vector<int>(N, 0)};
  init.score = score(best_team(init));
  priority_queue<Space> pq;
  pq.push(init);

  for (int c=0; c<C-1; c++) {
    Space S = pq.top(); pq.pop();
    auto best = best_team(S);

    // build disjoint subspaces
    for (int k=S.team.size(); k<K; k++) {
      S.vst[best[k]] = 1;
      auto nxt = best_team(S);
      if (!nxt.empty()) {
        S.score = score(nxt);
        pq.push(S);
      }
      S.team.push_back(best[k]);
    }
  }

  cout << pq.top().score << endl;

  ////////////////////////////////
  return 0;
}
