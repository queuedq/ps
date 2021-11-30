#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
string S[25];

bool cmp(const string &a, const string &b) { return a+b > b+a; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  priority_queue<string, vector<string>, decltype(&cmp)> pq(cmp);
  for (int i=0; i<N; i++) { cin >> S[i]; pq.push(S[i]); }

  while (!pq.empty()) {
    string s = pq.top(); pq.pop();
    cout << s[0];
    if (s.size() > 1) pq.push(s.substr(1));
  }

  ////////////////////////////////
  return 0;
}
