#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Student {
  string name;
  int kor, eng, mat;

  bool operator<(const Student &rhs) const {
    if (kor != rhs.kor) return kor > rhs.kor;
    if (eng != rhs.eng) return eng < rhs.eng;
    if (mat != rhs.mat) return mat > rhs.mat;
    return name < rhs.name;
  }
};

int N;
vector<Student> students;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    Student s;
    cin >> s.name >> s.kor >> s.eng >> s.mat;
    students.push_back(s);
  }
  sort(students.begin(), students.end());

  for (int i=0; i<N; i++) cout << students[i].name << '\n';

  ////////////////////////////////
  return 0;
}
