#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MF = 9; // max features
int N, R;
vector<string> stations;
unordered_map<string, int> feat_ids;

unordered_map<string, int> features; // station feature set (bitfield)
int cnt[1<<MF]; // number of stations for feature sets

int get_feat_id(const string &feat, bool create=false) {
  if (feat_ids.count(feat)) return feat_ids[feat];
  if (create) return feat_ids[feat] = sz(feat_ids);
  return -1; // not found
}

int parse_feats(const string &new_feats, bool create=false) { // returns bitfield of features
  int f = 0, pos = 0;
  while (pos < new_feats.size()) {
    int nxt = new_feats.find(',', pos);
    if (nxt == string::npos) nxt = new_feats.size();

    int id = get_feat_id(new_feats.substr(pos, nxt - pos), create);
    if (id == -1) return -1; // not found
    f |= 1 << id;

    pos = nxt + 1;
  }
  return f;
}

void update_feats(const string &station, const string &new_feats) {
  // remove previous features
  int f = features[station];
  for (int m=0; m<1<<MF; m++) {
    if ((m & f) == m) cnt[m]--;
  }

  // update new features
  f = features[station] = parse_feats(new_feats, true);
  for (int m=0; m<1<<MF; m++) {
    if ((m & f) == m) cnt[m]++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string station; cin >> station;
    stations.push_back(station);
  }

  cin >> R;
  for (int i=0; i<R; i++) {
    string query; cin >> query;
    if (query == "U") {
      string station, feats;
      cin >> station >> feats;
      update_feats(station, feats);

    } else {
      string feats;
      cin >> feats;
      int f = parse_feats(feats, false);
      if (f != -1) cout << cnt[f] << endl;
      else cout << 0 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
