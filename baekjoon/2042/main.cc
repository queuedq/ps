#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20; // 세그트리의 크기, N보다 큰 2의 거듭제곱
lld N, M, K, seg[ST*2]; // 배열은 세그트리 크기의 2배로 잡음 (N*4 크기로 잡아도 OK)

void build() {
  // 세그트리의 리프 노드는 입력을 통해 미리 채워진 상태
  // 역순으로 보면서 세그트리의 내부 노드를 채움
  for (int n=ST-1; n>0; n--) {
    seg[n] = seg[n*2] + seg[n*2+1];
  }
}

void update(int i, lld val) {
  int n = ST+i; // 세그트리의 리프 노드 중 i번째 위치
  seg[n] = val;
  for (n /= 2; n >= 1; n /= 2) { // 마지막의 n /= 2를 통해 부모 노드를 따라감
    seg[n] = seg[n*2] + seg[n*2+1];
  }
}

lld query(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0; // 현재 보는 문제가 쿼리 구간 밖에 있는 base case
  if (l <= nl && nr <= r) return seg[n]; // 현재 보는 문제가 쿼리 구간 안에 있는 base case
  int mid = (nl+nr+1) / 2;
  return query(n*2, nl, mid-1, l, r) + query(n*2+1, mid, nr, l, r); // 분할된 문제를 합침
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    lld x; cin >> x;
    seg[ST+i] = x; // 세그트리의 리프 노드 중 i번째 위치
  }

  build();

  for (int i=0; i<M+K; i++) {
    lld a, b, c; cin >> a >> b >> c;
    if (a == 1) {
      update(b, c);
    } else {
      // n: 루트 노드인 1번 노드에서 시작
      // nl: 전체 구간의 왼쪽 끝 인덱스인 0에서 시작
      // nr: 전체 구간의 오른쪽 끝 인덱스인 ST-1에서 시작
      cout << query(1, 0, ST-1, b, c) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
