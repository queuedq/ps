#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

vector<int> reduce(vector<int> &sums) {
  int a = sums[1];
  ans.push_back(a);

  vector<int> res;
  multiset<int> S;

  for (auto x: sums) {
    if (S.count(x)) {
      S.erase(S.find(x));
      continue;
    } else {
      res.push_back(x);
      S.insert(x+a);
    }
  }
  return res;
}

int main() {
  int N; cin >> N;
  vector<int> sums(1<<N);
  for (int i=0; i<1<<N; i++) cin >> sums[i];
  sort(sums.begin(), sums.end());

  while (sums.size() > 1) sums = reduce(sums);
  for (auto a: ans) cout << a << " ";
  cout << endl;
  return 0;
}
