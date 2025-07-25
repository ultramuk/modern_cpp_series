#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
void printValue(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "정수형 값: " << value << "\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "실수형 값: " << value << "\n";
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "문자열 값: " << value << "\n";
    } else {
        std::cout << "지원하지 않는 타입입니다.\n";
    }
}

int main() {
    printValue(42);                 // 정수형
    printValue(3.14);               // 실수형
    printValue(std::string("Hi"));  // 문자열
    printValue(true);               // 정수형
}
