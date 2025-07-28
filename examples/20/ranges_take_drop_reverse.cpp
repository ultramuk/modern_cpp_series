#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> v{ 10, 20, 30, 40, 50, 60 };

    auto view = v
        | std::views::drop(2)  // 앞에서 2개 제거 -> 30, 40, 50, 60
        | std::views::take(2)  // 앞에서 2개만 -> 30, 40
        | std::views::reverse; // 역순으로 -> 40, 30

    for (int x : view) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}