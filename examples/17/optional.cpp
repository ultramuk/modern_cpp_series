#include <iostream>
#include <optional>
#include <string>

// 입력이 유효한 경우에만 정수로 변환하는 함수
std::optional<int> toInt(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::nullopt;
    }
}

// optional을 사용하는 함수
void printConversionResult(const std::string& input) {
    auto result = toInt(input);

    if(result.has_value()) {
        std::cout << "변환 성공: " << result.value() << "\n";
    } else {
        std::cout << "변환 실패: 유효하지 않은 입력입니다.\n";
    }
}
int main() {
    printConversionResult("123");
    printConversionResult("3.14");
    printConversionResult("hello");
    printConversionResult("456");

    return 0;
}
