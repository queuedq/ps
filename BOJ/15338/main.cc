#include <bits/stdc++.h>
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A, B, Q;

struct Letter {
  int x;
  char c;
};

// hints for duplicate substrings are partitioned into sections
struct Section {
  int s; // section start
  int m = N; // mod = dist between duplicate substrings
  unordered_map<int, char> letters; // letters for each position mod m

  bool operator<(const Section &S) const { return s < S.s; }
};

vector<Letter> L;
vector<Section> S;

int find_section(int x) {
  return upper_bound(S.begin(), S.end(), Section{x, 0, {}}) - S.begin() - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> A >> B >> Q;
  for (int i=0; i<A; i++) {
    int x; char c; cin >> x >> c;
    L.push_back({x, c});
  }

  S.push_back({1, N, {}});
  for (int i=1; i<=B; i++) {
    int y, h; cin >> y >> h;
    S.push_back({y, (h ? y-h : N), {}});
  }

  // propagate letters to left
  for (auto [x, c]: L) {
    while (x > 0) {
      int i = find_section(x);
      auto &[s, m, letters] = S[i];
      
      letters[x % m] = c;

      // jump to next section
      int jumps = (x-s) / m + 1;
      x -= jumps * m;
    }
  }

  // propagate queries to left
  string ans(Q, '?');
  for (int q=0; q<Q; q++) {
    int z; cin >> z;

    while (z > 0) {
      int i = find_section(z);
      auto &[s, m, letters] = S[i];

      if (letters.count(z % m)) { ans[q] = letters[z % m]; break; }

      // jump to next section
      int jumps = (z-s) / m + 1;
      z -= jumps * m;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
