#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

template<class T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "[";
  for (int i=0; i<(int)vec.size()-1; i++) os << vec[i] << ", ";
  if (!vec.empty()) os << vec.back();
  os << "]";
  return os;
}

////////////////////////////////////////////////////////////////
const int MN = 13;
const int MX = 1<<13;
const lld INF = LLONG_MAX;
vector<pair<int, pii>> adj[MX][2];
int N, W[MN], T[MN], trust[MN][MN], B;
bool vst[MX][2];
lld dst[MX][2];

inline int flip_mask(int mask) { return mask ^ ((1<<N) - 1); }

vector<int> get_group(int mask) {
  vector<int> group;
  for (int i=0; i<N; i++) {
    if (mask>>i & 1) group.push_back(i);
  }
  return group;
}

int get_mask(vector<int> &group) {
  int mask = 0;
  for (int i: group) mask |= 1<<i;
  return mask;
}

vector<int> kth_subgroup(vector<int> &group, int k) {
  vector<int> subgroup;
  for (int i=0; i<group.size(); i++) {
    if (k>>i & 1) subgroup.push_back(group[i]);
  }
  return subgroup;
}

bool group_trust(vector<int> &group) {
  if (group.size() == 1) return true;
  for (int i: group) {
    bool ok = false;
    for (int j: group) {
      if (trust[i][j]) { ok = true; break; }
    }
    if (!ok) return false;
  }
  return true;
}

int group_time(vector<int> &group) {
  int t = 0;
  for (int i: group) t = max(t, T[i]);
  return t;
}

int group_weight(vector<int> &group) {
  int w = 0;
  for (int i: group) w += W[i];
  return w;
}

void get_next_states(int remaining, bool has_map) {
  if (has_map) {
    vector<int> group = get_group(remaining);

    for (int k = 1; k < 1<<group.size(); k++) {
      vector<int> subgroup = kth_subgroup(group, k);
      if (!group_trust(subgroup)) continue;
      if (group_weight(subgroup) > B) continue;

      int next_remaining = remaining ^ get_mask(subgroup);
      int t = group_time(subgroup);

      adj[remaining][has_map].push_back({t, {next_remaining, !has_map}});
      // cout << get_group(next_remaining) << " " << !has_map << endl;
    }
  } else {
    vector<int> group = get_group(flip_mask(remaining));

    for (int k = 1; k < 1<<group.size(); k++) {
      vector<int> subgroup = kth_subgroup(group, k);
      if (!group_trust(subgroup)) continue;
      if (group_weight(subgroup) > B) continue;

      int next_remaining = remaining ^ get_mask(subgroup);
      int t = group_time(subgroup);

      adj[remaining][has_map].push_back({t, {next_remaining, !has_map}});
      // cout << get_group(next_remaining) << " " << !has_map << endl;
    }
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

  for (int remaining = 0; remaining < 1<<N; remaining++) {
    for (bool has_map : {true, false}) {
      // cout << "========" << endl;
      // cout << get_group(remaining) << " " << has_map << endl;
      // cout << "--------" << endl;
      get_next_states(remaining, has_map);
      dst[remaining][has_map] = INF;
    }
  }
  // cout << "================" << endl;

  priority_queue< pair<int, pii>
                , vector<pair<int, pii>>
                , greater<pair<int, pii>>
                > pq;
  pq.push((pair<int, pii>){0, {(1<<N)-1, 1}});
  while (!pq.empty()) {
    auto [t, u] = pq.top(); pq.pop();
    auto [remaining, has_map] = u;
    if (dst[remaining][has_map] != INF) continue;
    dst[remaining][has_map] = t;
    // cout << get_group(remaining) << " " << has_map << " " << t << endl;
    
    for (auto [dt, v]: adj[remaining][has_map]) pq.push({t+dt, v});
  }

  if (dst[0][false] == INF) cout << -1 << endl;
  else cout << dst[0][false] << endl;

  ////////////////////////////////
  return 0;
}
