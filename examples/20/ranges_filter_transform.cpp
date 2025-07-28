#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers {1, 2, 3, 4, 5, 6};

    // 짝수만 필터링하고 제곱하는 뷰 생성
    auto even_squared = numbers
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });

    std::cout << "짝수의 제곱: ";
    for (int val : even_squred) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
