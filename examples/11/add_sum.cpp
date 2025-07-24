#include <iostream>
#include <vector>

// auto 타입 추론 메커니즘
auto sum(const std::vector<int>& data) {
    int total = 0;
    for (const auto& value : data) {
        total += value;
    }
    return total;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::cout << "Sum : " << sum(data) << std::endl;

    return 0;
}
