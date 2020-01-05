#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<string> cards;
map<string, int> cmap;
map<char, int> ctoi = {{'S', 0}, {'E', 1}, {'T', 2}};
char itoc[3] = {'S', 'E', 'T'};

string getSet(const string& a, const string& b) {
  vector<char> v;
  for (int i = 0; i < a.size(); i++) {
    v.push_back(itoc[(6 - ctoi[a[i]] - ctoi[b[i]]) % 3]);
  }
  return string(v.begin(), v.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int n, k; cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string card; cin >> card;
    cards.push_back(card);
    cmap[card]++;
  }

  lld ans = 0;
  for (int i = 0; i < cards.size(); i++) {
    for (int j = 0; j < i; j++) {
      string s = getSet(cards[i], cards[j]);
      ans += cmap[s];
      if (s == cards[i]) ans--;
      if (s == cards[j]) ans--;
    }
  }

  cout << ans / 3 << endl;

  ////////////////////////////////
  return 0;
}
