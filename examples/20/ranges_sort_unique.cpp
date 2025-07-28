#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> v{ 3, 5, 3, 2, 4, 2, 1, 5 };

    std::ranges::sort(v);

    // 중복 제거 view (정렬 후에만 사용 가능)
    auto unique_view = v | std::views::unique;

    std::cout << "중복 제거 후: ";
    for (int n : unique_view) std::cout << n << ' ';
    std::cout << "\n";

    return 0;
}