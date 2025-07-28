#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<std::string> words { "Modern", "C++", "Rocks" };

    auto lengths = words | std::views::transform([](const std::string& s) {
        return s.size();
    });

    for (auto len : lengths) std::cout << len << " ";
    std::cout << "\n";

    return 0;
}