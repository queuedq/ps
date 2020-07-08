#include <bits/stdc++.h>
#include "bogoSort.h"

using namespace std;

vector<int> arr;
vector<int> objective;

void sort_array(int N) {
	arr = copy_array();
	objective = arr;
	sort(objective.begin(), objective.end());

	for (int st=0; st<N; st++) {
		while (arr[st] != objective[st]) {
			int ed = st;
			for (; ed<N; ed++) {
				if (arr[ed] == objective[st]) break;
			}

			shuffle_array(st, ed);
			arr = copy_array();
		}
	}
}
