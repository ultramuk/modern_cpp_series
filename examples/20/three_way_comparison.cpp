#include <compare>
#include <iostream>

struct Point {
    int x;
    int y;

    // three-way 비교 연산자
    auto operator<=>(const Point&) const = default;
};

int main() {
    Point a{1, 2};
    Point b{1, 3};
    Point c{1, 2};

    std::cout << std::boolalpha;
    std::cout << "a == c: " << (a == c) << "\n"; // true
    std::cout << "a < b: " << (a < b) << "\n"; // true
    std::cout << "b > c: " << (b > c) << "\n"; // true

    // 직접 비교 결과 타입도 얻을 수 있음
    auto result = (a <=> b);
    if (result < 0) std::cout << "a < b\n";
    else if (result > 0) std::cout << "a > b\n";
    else std::cout << "a == b\n";

    return 0;
}

auto operator<=>(const Point& lhs, const Point& rhs) {
    if (lhs.x != rhs.x) return lhs.x <=> rhs.x;
    return lhs.y <=> rhs.y;
}