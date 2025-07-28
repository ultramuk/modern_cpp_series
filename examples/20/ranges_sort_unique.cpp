#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> v{ 3, 5, 3, 2, 4, 2, 1, 5 };

    std::ranges::sort(v);
    auto last = std::ranges::unique(v);
    v.erase(last.begin(), last.end());

    std::cout << "중복 제거 후: ";
    for (int n : v) std::cout << n << ' ';
    std::cout << "\n";

    return 0;
}