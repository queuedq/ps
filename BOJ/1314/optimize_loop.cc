#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 13;
const int MX = 1<<13;
const lld INF = LLONG_MAX;
vector<pair<int, pii>> adj[MX][2];
int N, W[MN], T[MN], trust[MN][MN], B;
int gW[MX], gT[MX], gtrust[MX];
bool vst[MX][2];
lld dst[MX][2];

int group_weight(int group) {
  int w = 0;
  for (int i=0; i<N; i++) {
    if (group>>i & 1) w += W[i];
  }
  return w;
}

int group_time(int group) {
  int t = 0;
  for (int i=0; i<N; i++) {
    if (group>>i & 1) t = max(t, T[i]);
  }
  return t;
}

bool group_trust(int group) {
  int cnt = 0;
  for (int i=0; i<N; i++) {
    if (group>>i & 1) cnt++;
  }
  if (cnt == 1) return true;

  for (int i=0; i<N; i++) {
    if (!(group>>i & 1)) continue;
    bool ok = false;
    for (int j=0; j<N; j++) {
      if (!(group>>j & 1)) continue;
      if (trust[i][j]) { ok = true; break; }
    }
    if (!ok) return false;
  }
  return true;
}

void build_graph(int group, bool exit) {
  for (int sg = group; sg >= 1; sg = (sg-1) & group) {
    if (!gtrust[sg]) continue;
    if (gW[sg] > B) continue;

    int next_group = ((1<<N)-1) ^ group ^ sg;
    int t = gT[sg];

    adj[group][exit].push_back({t, {next_group, !exit}});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> W[i] >> T[i];
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<N; j++) trust[i][j] = S[j] == 'Y';
    trust[i][i] = false;
  }
  cin >> B;

  for (int group = 0; group < 1<<N; group++) {
    gW[group] = group_weight(group);
    gT[group] = group_time(group);
    gtrust[group] = group_trust(group);

    for (bool exit : {false, true}) {
      build_graph(group, exit);
      dst[group][exit] = INF;
    }
  }

  priority_queue< pair<int, pii>
                , vector<pair<int, pii>>
                , greater<pair<int, pii>>
                > pq;
  pq.push((pair<int, pii>){0, {(1<<N)-1, false}});

  while (!pq.empty()) {
    auto [t, u] = pq.top(); pq.pop();
    auto [group, exit] = u;
    if (dst[group][exit] != INF) continue;
    dst[group][exit] = t;
    
    for (auto [dt, v]: adj[group][exit]) pq.push({t+dt, v});
  }

  if (dst[(1<<N)-1][true] == INF) cout << -1 << endl;
  else cout << dst[(1<<N)-1][true] << endl;

  ////////////////////////////////
  return 0;
}
