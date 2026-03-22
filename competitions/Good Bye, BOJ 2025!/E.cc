#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;

bool is_lower(char c) { return 'a' <= c && c <= 'z'; }

////////////////////////////////////////////////////////////////
const lld INF = 2e18;
int N, Q;
string S[26];
vector<lld> idx[26];
lld loop_len[26];

struct Frame {
  // frame at i th index of S[k] / len = idx[k][i]
  int k, i;
};

struct Context { // = call stack
  vector<Frame> frames;
  int vst[26] = {};

  int get_frame_index(int k) { // frame index for S[k]
    for (int f=0; f<sz(frames); f++) {
      if (frames[f].k == k) return f;
    }
    return -1;
  }

  lld get_loop_size(int k) {
    int f = get_frame_index(k);
    if (f == -1) return 0; // no loop

    lld sum = 0;
    for (; f<sz(frames); f++) {
      sum = min(sum + idx[frames[f].k][frames[f].i], INF);
    }
    return sum;
  }

  // always make sure last frame points to lowercase letter
  char step() {
    auto &[k, i] = frames.back();
    char c = S[k][i];
    assert(is_lower(c));
    i++;

    // pop finished frames
    while (!frames.empty()) {
      auto [k, i] = frames.back();
      if (i == sz(S[k])) {
        frames.pop_back();
        if (!frames.empty()) frames.back().i++;
      } else break;
    }

    // push new frame if uppercase
    if (!frames.empty()) {
      auto [k, i] = frames.back();
      char c = S[k][i];
      if (!is_lower(c)) frames.push_back({c-'A', 0});
    }

    return c;
  }

  void debug() {
    for (auto &[k, i]: frames) {
      cout << k << " " << i << " / ";
    }
    cout << endl;
  }
};

void debug() {
  for (int k=0; k<N; k++) {
    cout << S[k] << endl;
    for (int i=0; i<=sz(S[k]); i++) {
      if (idx[k][i] >= INF) cout << "INF ";
      else cout << idx[k][i] << " ";
    }
    cout << " / " << loop_len[k] << endl;
  }
}

////////////////////////////////////////////////////////////////

lld calc_index(int k, Context &ctx) {
  // loop check
  lld loop = ctx.get_loop_size(k);
  if (loop) {
    loop_len[k] = loop;
    return INF;
  }

  // cache check
  if (sz(idx[k]) > 0) return idx[k].back(); // index cached

  // calc index
  int n = sz(S[k]);
  idx[k].assign(n+1, INF);
  idx[k][0] = 0;
  for (int i=0; i<n; i++) {
    auto &nxt_idx = idx[k][i+1];

    if (is_lower(S[k][i])) nxt_idx = min(idx[k][i] + 1, INF);
    else {
      // recurse
      ctx.frames.push_back({k, i});
      lld len = calc_index(S[k][i]-'A', ctx);
      ctx.frames.pop_back();

      nxt_idx = min(idx[k][i] + len, INF);
      if (nxt_idx >= INF) break;
    }
  }

  // return length
  return idx[k].back();
}

void get_context(int k, lld pos, Context &ctx) {
  // skip loop
  if (loop_len[k]) pos %= loop_len[k];

  // save context frame
  int i = upper_bound(all(idx[k]), pos) - idx[k].begin() - 1;
  ctx.frames.push_back({k, i});
  ctx.vst[k] = 1;

  // recurse
  if (!is_lower(S[k][i])) {
    get_context(S[k][i]-'A', pos - idx[k][i], ctx);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;

  for (int k=0; k<N; k++) cin >> S[k];
  for (int k=0; k<N; k++) {
    Context ctx;
    calc_index(k, ctx);
  }

  // debug();

  for (int q=0; q<Q; q++) {
    lld k, l, r; cin >> k >> l >> r;
    k--; l--; r--;
    Context ctx;
    get_context(k, l, ctx);

    while (l <= r) {
      char c = ctx.step();
      // cout << c << endl;
      // ctx.debug();
      cout << c;
      l++;
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
