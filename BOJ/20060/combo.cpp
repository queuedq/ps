#include <bits/stdc++.h>
#include "combo.h"
using namespace std;

std::string guess_sequence(int N) {
  char S0;
  if (press("AB") > 0) {
    if (press("A") > 0) S0 = 'A';
    else S0 = 'B';
  } else {
    if (press("X") > 0) S0 = 'X';
    else S0 = 'Y';
  }

  if (N == 1) return string(1, S0);

  string S(1, S0);
  string btn = "ABXY";
  btn.erase(remove(btn.begin(), btn.end(), S0), btn.end());

  for (int i=0; i<N-2; i++) {
    int cnt = press(S+btn[0]+btn[0] + S+btn[0]+btn[1] + S+btn[0]+btn[2] + S+btn[1]);
    if (cnt == S.size()) S.push_back(btn[2]);
    else if (cnt == S.size() + 1) S.push_back(btn[1]);
    else S.push_back(btn[0]);
  }

  if (press(S+btn[0] + S+btn[1]) == S.size()) S.push_back(btn[2]);
  else if (press(S+btn[0]) == S.size()) S.push_back(btn[1]);
  else S.push_back(btn[0]);

  return S;
}
