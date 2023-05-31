#include "workshop.h"

#include <array>
#include <vector>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::max;

namespace {
	void ensure(bool p, const char *err) {
		if (!p) {
			cout << err << endl;
			exit(0);
		}
	}
}

int main() {
	int q;
	cin >> q;
	init();
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		std::vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		{
			std::vector<int> p = v;
			for (int j = 0; j < n; j++) {
				int a = p[j];
				int b = p[(j + 1) % n];
				v[j] = morning(a, b);
				ensure(v[j] >= 0 && v[j] < 1'000'000'000, "Wrong Answer [1]");
			}
		}
		{
			std::vector<int> p = v;
			for (int j = 0; j < n; j++) {
				int a = p[(j + n-1) % n];
				int b = p[j];
				int c = p[(j + 1) % n];
				v[j] = afternoon(a, b, c);
				ensure(v[j] >= 0 && v[j] < 1'000'000'000, "Wrong Answer [2]");
			}
		}
		{
			std::vector<int> p = v;
			for (int j = 0; j < n; j++) {
				int a = p[(j + n-1) % n];
				int b = p[j];
				int c = p[(j + 1) % n];
				v[j] = evening(a, b, c);
				ensure(v[j] >= 0 && v[j] < 40, "Wrong Answer [3]");
			}
		}
		int ans = 0;
		for (int j = 0; j < n; j++) {
			ans = max(ans, v[j] + 1);
			ensure(v[j] != v[(j + 1) % n], "Wrong Answer [4]");
		}
		cout << "Correct!" << endl;
		cout << "m = " << ans << endl;
	}
	return 0;
}
