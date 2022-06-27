#include <iostream>
#include <vector>

extern long long findMinClicks(int M, int R, std::vector <std::pair<int, int> > P);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, R;
	std::cin >> N >> M >> R;
	std::vector<std::pair<int, int> > P(N);
	for (int i = 0; i < N; i++) std::cin >> P[i].first >> P[i].second;

	std::cout << findMinClicks(M, R, P) << "\n";

	return 0;
}
