#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 100005
int N;
lld A[MAX_N], B[MAX_N];
lld total[MAX_N];
list<pll> lines;  // {a, b}: y = ax + b

double inter(pll l1, pll l2) {
  lld a1 = l1.first, b1 = l1.second;
  lld a2 = l2.first, b2 = l2.second;
  assert(a1 != a2);
  return (b2 - b1) / (a1 - a2);
}

void insert(pll line) {
  while (lines.size() > 1) {
    pll first = lines.back();
    pll second = *next(lines.rbegin());
    double p = inter(first, second);
    double np = inter(line, first);
    if (np <= p) {
      lines.pop_back();
    } else {
      break;
    }
  }
  lines.push_back(line);
}

lld query(lld t) {
  while (lines.size() > 1) {
    pll first = lines.front();
    pll second = *next(lines.begin());
    double p = inter(first, second);
    if (p <= t) {
      lines.pop_front();
    } else {
      break;
    }
  }
  pll l = lines.front();
  return l.first * t + l.second;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  for (int i = 0; i < N; i++) { cin >> B[i]; }
}

lld calc() {
  insert({B[0], 0});
  for (int i = 1; i < N; i++) {
    total[i] = query(A[i]);
    insert({B[i], total[i]});
  }
  return total[N - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  cout << calc() << endl;

  ////////////////////////////////
  return 0;
}
