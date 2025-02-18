#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
using lld = long long;
using pii = pair<int, int>;

////////////////////////////////////////////////////////////////
const int MQ = 202020;
const int ST = 1<<17;
string S;

struct SegTree {
  // node = interval
  // str = set of nodes (union find)
  int seg[ST*2]; // latest node id
  int par[MQ];

  int sid[MQ]; // nid (root) -> string id
  int nid[MQ]; // sid -> node id (root)

  void reset() {
    for (int i=0; i<MQ; i++) par[i] = i;
    update(0, ST-1, 1);
    nid[1] = 1;
    sid[1] = 1;
  }

  // UF
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  int merge(int x, int y) { // x <- y
    x = find(x), y = find(y);
    if (!x) return y;
    if (!y) return x;
    if (x != y) par[y] = x;
    return x;
  }

  // seg
  void update(int l, int r, int n) {
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) seg[l++] = n;
      if (r&1) seg[--r] = n;
    }
  }

  int get_node(int i) {
    int node = 0;
    for (int n=i+ST; n>0; n/=2) node = max(node, seg[n]);
    return node;
  }

  int get_str(int i) {
    int n = get_node(i);
    return sid[find(n)];
  }

  void set_str(int n, int s) {
    sid[n] = s;
    nid[s] = n;
  }
};
SegTree seg[26];

vector<int> word_count(string word) {
  vector<int> cnt(26);
  for (auto c: word) cnt[c-'a']++;
  return cnt;
}

vector<string> solution(string _S, vector<string> query) {
  S = _S;
  int node_id = 1, str_id = 1;
  vector<string> result;

  // init
  for (int c=0; c<26; c++) seg[c].reset();

  // query
  for (auto qry: query) {
    stringstream ss(qry);
    int q, x, y; string word;
    ss >> q;

    if (q == 1) {
      ss >> x >> y;
      x--, y--;

      int sx = seg[S[x]-'a'].get_str(x);
      int sy = seg[S[y]-'a'].get_str(y);
      if (sx == sy) result.push_back("YES");
      else result.push_back("NO");

    } else if (q == 2) {
      ss >> x >> word;
      x--;
      auto cnt = word_count(word);

      int sx = seg[S[x]-'a'].get_str(x);
      str_id++; // new str
      for (int c=0; c<26; c++) if (cnt[c]) {
        int n = seg[c].nid[sx];
        seg[c].set_str(0, sx); // reset removed
        seg[c].set_str(n, str_id);
      }

    } else if (q == 3) {
      ss >> x >> y >> word;
      x--, y--;
      auto cnt = word_count(word);

      str_id++; // new str
      node_id++; // new node
      for (int c=0; c<26; c++) if (cnt[c]) {
        seg[c].update(x, y, node_id);
        seg[c].set_str(node_id, str_id);
      }

    } else if (q == 4) {
      ss >> x >> y;
      x--, y--;

      int sx = seg[S[x]-'a'].get_str(x);
      int sy = seg[S[y]-'a'].get_str(y);
      if (sx > sy) swap(sx, sy); // merge to oldest
      for (int c=0; c<26; c++) {
        int nx = seg[c].nid[sx], ny = seg[c].nid[sy];
        int n = seg[c].merge(nx, ny);
        seg[c].set_str(0, sy); // reset removed
        seg[c].set_str(n, sx);
      }

    } else if (q == 5) {

      vector<int> cnt[26];
      for (int c=0; c<26; c++) cnt[c].resize(str_id+1);

      // collect
      for (int i=0; i<sz(S); i++) {
        int s = seg[S[i]-'a'].get_str(i);
        cnt[S[i]-'a'][s]++;
      }

      // print
      for (int i=1; i<=str_id; i++) {
        stringstream out;
        for (int c=0; c<26; c++) if (cnt[c][i]) {
          out << (char)(c+'a') << " " << cnt[c][i] << " ";
        }

        string ans = out.str();
        if (sz(ans)) ans.pop_back();
        if (sz(ans)) result.push_back(ans);
      }
    }

    // for (int i=0; i<sz(S); i++) {
    //   cout << seg[S[i]-'a'].get_str(i) << " \n"[i==sz(S)-1];
    // }
  }

  return result;
}

int main() {
  string S; cin >> S;
  int Q; cin >> Q;
  vector<string> queries(Q);
  cin.ignore();
  for (int i=0; i<Q; i++) getline(cin, queries[i]);

  auto result = solution(S, queries);
  // auto result = solution("abacadae", {"3 1 4 abae", "1 1 5", "3 3 6 da", "4 1 6", "2 6 ab", "5"});
  // for (auto x: result) cout << x << endl;
  return 0;
}
