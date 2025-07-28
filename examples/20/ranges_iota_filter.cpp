#include <iostream>
#include <ranges>

int main() {
    // 무한 시퀀스 (0부터 시작)
    auto even = std::views::iota(0) // 0, 1, 2, 3, ...
        | std::views::filter([](int x) { return x % 2 == 0; }) // 짝수만
        | std::views::take(5);      // 앞에서 5개만

    for (int n : evens) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}