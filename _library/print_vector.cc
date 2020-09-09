#include "template.h"

template<class T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "[";
  for (int i=0; i<vec.size()-1; i++) os << vec[i] << ", ";
  if (!vec.empty()) os << vec.back();
  os << "]";
  return os;
}

template<class T>
string to_string(T arr[], int size) {
	ostringstream os;
  os << "[";
	for (int i = 0; i<size-1; i++) os << arr[i] << ",";
  if (size > 0) os << arr[size-1];
  os << "]";
	return os.str();
}
