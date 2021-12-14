#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Point { int num, cnt; };

struct Tri {
  int a, b, c;
  Tri(int a0, int b0, int c0) {
    int t[3] = {a0, b0, c0};
    sort(t, t+3);
    a = t[0], b = t[1], c = t[2];
  }
  bool operator <(const Tri &T) const {
    return tie(a, b, c) < tie(T.a, T.b, T.c);
  }
};

bool find(vector<Point> &A, vector<Tri> &ans) {
  int N = A.size();
  if (N == 3) {
    if (A[0].cnt == 1 && A[1].cnt == 1 && A[2].cnt == 1) {
      ans.push_back(Tri(A[0].num, A[1].num, A[2].num));
      return true;
    } else {
      return false;
    }
  }

  int j = -1;
  for (int i=0; i<N; i++) {
    if (A[i].cnt == 1) { j = i; break; }
  }

  if (j == -1) return false;
  if (--A[(j+N-1) % N].cnt == 0 || --A[(j+1) % N].cnt == 0) return false;

  ans.push_back(Tri(A[(j+N-1) % N].num, A[j].num, A[(j+1) % N].num));
  A.erase(A.begin() + j);
  return true;
}

void solve() {
  int test, N;
  cin >> test >> N;

  vector<Point> A(N);
  vector<Tri> ans;
  for (int i=0; i<N; i++) { A[i].num = i+1; cin >> A[i].cnt; }
  
  bool ok = true;
  for (int i=0; i<N-2 && ok; i++) ok = find(A, ans);

  if (ok) {
    cout << test << " Y\n";
    sort(ans.begin(), ans.end());
    for (auto [a, b, c]: ans) cout << a << " " << b << " " << c << "\n";
  } else {
    cout << test << " N\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
