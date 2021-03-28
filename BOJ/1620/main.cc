#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
string pokemon[101010];
map<string, int> pokemonNum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> pokemon[i];
    pokemonNum[pokemon[i]] = i;
  }

  for (int i=0; i<M; i++) {
    string query; cin >> query;
    if ('0' <= query[0] && query[0] <= '9') {
      cout << pokemon[stoi(query)] << '\n';
    } else {
      cout << pokemonNum[query] << '\n';
    }
  }

  ////////////////////////////////
  return 0;
}
