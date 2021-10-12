#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int s, int e, int k) {
  if (s == e) return a[s];

  // pivot
  swap(a[rand() % (e-s+1) + s], a[e]);

  // 3-way partition
  int l = s, r = e-1, i = s;
  while (i <= r) {
    if (a[i] < a[e]) swap(a[i++], a[l++]);
    else if (a[i] > a[e]) swap(a[i], a[r--]);
    else i++;
  }
  swap(a[r+1], a[e]);

  // recursion
  if (k < l) return solve(a, s, l-1, k);
  if (k > r) return solve(a, r+1, e, k);
  return a[l];
}

int kth(vector<int> &a, int k) {
  srand(42);
  return solve(a, 0, a.size()-1, k-1);
}

// int main() {
//   vector<int> a;
//   for (int i=1; i<=10; i++) a.push_back(i*i);
//   for (int i=1; i<=10; i++) cout << kth(a, i) << endl;
//   return 0;
// }
