#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 1000005
int N;
lld A[MAX_N];
int back[MAX_N];
vector<lld> S, idx;
lld L[MAX_N];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

void reset() {
  for (int i = 0; i < N; i++) {
    back[i] = -1;
  }
}

void lis() {
  for (int i = 0; i < N; i++) {
    int at = lower_bound(S.begin(), S.end(), A[i]) - S.begin();
    if (at == S.size()) {
      S.push_back(A[i]);
      idx.push_back(i);
    } else {
      S[at] = A[i];
      idx[at] = i;
    }
    if (at != 0) back[i] = idx[at - 1];
  }

  int len = S.size(), i = idx[len - 1];
  while (len--) {
    L[len] = A[i];
    i = back[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  reset();
  input();
  lis();

  cout << S.size() << endl;
  for (int i = 0; i < S.size() - 1; i++) {
    cout << L[i] << " ";
  }
  cout << L[S.size() - 1] << endl;

  ////////////////////////////////
  return 0;
}
