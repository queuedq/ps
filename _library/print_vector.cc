#include "template.h"

template<class T>
ostream& operator << (ostream& os, vector<T> vec) {
  os << "{";
  if (vec.size() > 0) {
    copy(vec.begin(), vec.end() - 1, ostream_iterator<T>(os, ", "));
    os << *(vec.end() - 1);
  }
  os << "}";
  return os;
}

template<class T>
string arrToStr(T arr[], int size) {
	ostringstream os;
  os << "[";
	for (int i = 0; i < size - 1; i++) {
		os << arr[i] << ",";
	}
  os << arr[size - 1] << "]";

	return os.str();
}
