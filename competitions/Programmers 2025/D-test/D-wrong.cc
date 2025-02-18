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

  // UF
  void reset() {
    for (int i=0; i<MQ; i++) par[i] = i;
  }

  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  void merge(int x, int y) { // x <- y
    x = find(x), y = find(y);
    if (x == y) return;
    par[y] = x;
  }

  // seg
  void update(int l, int r, int v) {
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) seg[l++] = v;
      if (r&1) seg[--r] = v;
    }
  }

  int get_node(int i) {
    int node = -1;
    for (int n=i+ST; n>0; n/=2) node = max(node, seg[n]);
    return node;
  }

  int get_str(int i) {
    int n = get_node(i);
    return sid[find(n)];
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
  int node_id = 0, str_id = 0;
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
        seg[c].sid[n] = str_id;
      }

    } else if (q == 3) {
      ss >> x >> y >> word;
      x--, y--;
      auto cnt = word_count(word);

      str_id++; // new str
      node_id++; // new node
      for (int c=0; c<26; c++) if (cnt[c]) {
        seg[c].update(x, y, node_id);
        seg[c].sid[node_id] = str_id;
        seg[c].nid[str_id] = node_id;
      }

    } else if (q == 4) {
      ss >> x >> y;
      x--, y--;

      int sx = seg[S[x]-'a'].get_str(x);
      int sy = seg[S[y]-'a'].get_str(y);
      if (sx > sy) swap(sx, sy); // merge to oldest
      for (int c=0; c<26; c++) {
        seg[c].merge(seg[c].nid[sx], seg[c].nid[sy]);
        seg[c].sid[seg[c].nid[sx]] = sx;
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
      for (int i=0; i<=str_id; i++) {
        stringstream out;
        for (int c=0; c<26; c++) if (cnt[c][i]) {
          out << (char)(c+'a') << " " << cnt[c][i] << " ";
        }

        string ans = out.str();
        if (sz(ans)) ans.pop_back();
        if (sz(ans)) result.push_back(ans);
      }
    }
  }

  return result;
}

// int main() {

// }
