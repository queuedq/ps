#include "template.cc"

using llld = __int128;

string to_string (llld num) {
  const lld m = 1'000'000'000'000'000'000;
  string str;
  do {
    long long digits = num % m;
    auto digitsStr = to_string(digits);
    auto leading0s = (digits != num) ? string(18 - digitsStr.length(), '0') : "";
    str = leading0s + digitsStr + str;
    num = (num - digits) / m;
  } while (num != 0);
  return str;
}

////////////////////////////////////////////////////////////////

void usage() {
  llld x = (llld)123'456'789'123'456'789 * 1'000'000'000 + 123'456'789;
  cout << to_string(x) << endl;
}
