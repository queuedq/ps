#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

vector<int> solve(int N, const vector<int> A, int &sum) {
  if (N == 1) {
    sum = A[0];
    return {A[0]};
  }

  vector<int> B;

  int s1 = 0, s2 = 0;
  auto B1 = solve(N/2, vector(A.begin(), A.begin() + N-1), s1);
  auto B2 = solve(N/2, vector(A.begin() + N-1, A.begin() + 2*N-2), s2);
  if ((s1 + s2) % N == 0) {
    merge(B1.begin(), B1.end(), B2.begin(), B2.end(), back_inserter(B));
    sum = s1 + s2;
    return B;
  }

  vector<int> A3;
  int j = 0, k = 0;
  for (int i=0; i<A.size(); i++) {
    if (j < N/2 && A[i] == B1[j]) j++;
    else if (k < N/2 && A[i] == B2[k]) k++;
    else A3.push_back(A[i]);
  }

  int s3 = 0;
  auto B3 = solve(N/2, A3, s3);
  if ((s1 + s3) % N == 0) {
    merge(B1.begin(), B1.end(), B3.begin(), B3.end(), back_inserter(B));
    sum = s1 + s3;
    return B;
  }
  if ((s2 + s3) % N == 0) {
    merge(B2.begin(), B2.end(), B3.begin(), B3.end(), back_inserter(B));
    sum = s2 + s3;
    return B;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<int> A(2*N-1);
  for (int i=0; i<2*N-1; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int sum = 0;
  auto B = solve(N, A, sum);
  for (int i=0; i<B.size(); i++) {
    cout << B[i] << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
