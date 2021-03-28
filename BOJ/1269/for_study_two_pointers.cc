#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 200'005;
int A[MAXN], B[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int a, b; cin >> a >> b;

  for (int i=0; i<a; i++) cin >> A[i];
  for (int i=0; i<b; i++) cin >> B[i];

  // 집합 원소 정렬
  sort(A, A+a);
  sort(B, B+b);

  // i: A의 원소 인덱스, j: B의 원소 인덱스, cnt: 교집합 크기
  int i = 0, cnt = 0;

  for (int j=0; j<b; j++) {
    while (i < a && A[i] < B[j]) i++; // A[i]가 B[j] 이상이 되는 곳까지 i를 증가시킴
    if (A[i] == B[j]) cnt++; // 양쪽 원소가 같으면 교집합에 포함됨
  }

  cout << a + b - cnt*2 << endl;

  ////////////////////////////////
  return 0;
}
