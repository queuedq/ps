#include "liar.h"
#include <random>
#include <iostream>

int k, n;
int answer;
int lies = 0;
int total_ask = 0;
int total_elements = 0;

bool reverse() {
    static std::mt19937 engine{std::random_device{}()};
    return std::uniform_int_distribution<int>(0, 1)(engine) == 1;
}

bool ask(std::vector<int> v) {
    total_ask += 1;
    if (total_ask > 15'000) {
        std::cout << "[Wrong Answer] Total ask calls have exceeded 15,000." << "\n";
        std::exit(0);
    }

    total_elements += int(v.size());
    if (total_elements > 1'000'000) {
        std::cout << "[Wrong Answer] The total number of elements in ask calls has exceeded 1,000,000." << "\n";
        std::exit(0);
    }

    bool result = false;
    for (const auto &x: v) {
        if (x < 1 || x > n) {
            std::cout << "[Wrong Answer] An element in an ask call is out of range." << " "
                      << "Expected an element in the range [1, " << n << "], but found " << x << "." << "\n";
            std::exit(0);
        }
        result |= x == answer;
    }

    if (reverse() && lies < k) lies++, result ^= 1;
    else lies = 0;

    std::cout << "Asked [";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << (i == int(v.size()) - 1 ? "]" : ", ");
    }
    std::cout << " and the sample grader " << (lies == 0 ? "told the truth." : "lied.") << "\n";

    return result;
}

int main() {
    std::cin >> k >> n;
    std::cin >> answer;

    auto v = game(k, n);

    bool found = false;
    for (const auto &x: v) {
        if (x < 1 || x > n) {
            std::cout << "[Wrong Answer] An element in an ask call is out of range." << " "
                      << "Expected an element in the range [1, " << n << "], but found " << x << "." << "\n";
            std::exit(0);
        }
        found |= x == answer;
    }

    std::cout << "Final Output : [";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << (i == int(v.size()) - 1 ? "]" : ", ");
    }
    std::cout << ".\n";

    if (found)
        std::cout << "[Accepted]" << "\n"
                  << "Total ask calls : " << total_ask << ", total number of elements in aks calls : " << total_elements << ".\n";
    else std::cout << "[Wrong Answer] " << answer << " not included in the final output." << "\n";

    return 0;
}
