#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct File {
  string name;
  int owner_perm, group_perm, other_perm;
  string owner, group;
};

unordered_map<string, File> files;
set<pair<string, string>> user_groups;

bool query(const string &user, const string &file, const string &op) {
  File &f = files[file];

  int perm = 0;
  if (user == f.owner) perm = f.owner_perm;
  else if (user_groups.count({user, f.group})) perm = f.group_perm;
  else perm = f.other_perm;

  if (op == "R" && (perm & 4)) return true;
  if (op == "W" && (perm & 2)) return true;
  if (op == "X" && (perm & 1)) return true;
  return false;
}

void parse_user() {
  // parse line
  string line; getline(cin, line);
  string user;
  string groups_str;

  int pos = line.find(' ');
  if (pos == (int)string::npos) user = line; // no groups
  else user = line.substr(0, pos), groups_str = line.substr(pos + 1);

  // parse groups
  vector<string> groups;
  pos = 0;
  while (pos < (int)groups_str.size()) {
    int nxt = groups_str.find(',', pos);
    if (nxt == (int)string::npos) nxt = groups_str.size();
    groups.push_back(groups_str.substr(pos, nxt - pos));
    pos = nxt + 1;
  }
  groups.push_back(user);

  // save groups
  for (auto &g: groups) {
    user_groups.insert({user, g});
  }
}

void parse_file() {
  // parse line
  string file, owner, group; int perm;
  cin >> file >> perm >> owner >> group;

  // save file info
  auto &f = files[file];
  f.name = file, f.owner = owner, f.group = group;

  // parse permissions
  f.other_perm = perm % 10, perm /= 10;
  f.group_perm = perm % 10, perm /= 10;
  f.owner_perm = perm % 10, perm /= 10;
  assert(perm == 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int U, F; cin >> U >> F;
  cin.ignore();
  for (int i=0; i<U; i++) parse_user();
  for (int i=0; i<F; i++) parse_file();

  int Q; cin >> Q;
  for (int i=0; i<Q; i++) {
    string user, file, op;
    cin >> user >> file >> op;
    cout << query(user, file, op) << endl;
  }

  ////////////////////////////////
  return 0;
}
