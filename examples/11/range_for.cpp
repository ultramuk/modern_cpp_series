#include <iostream>
#include <vector>
#include <string>

// for (T x : container) : 값 복사됨 (string이라면 매 반복마다 복사 발생)
// for (const T& x : container) : 복사 없이 읽기 전용 접근
// for (T& x : container) : 직접 수정 가능 (원본 변경)

int main() {
    std::vector<std::string> fruits = {"apple", "banana", "cheryy"};

    std::cout << "[1] 기본 range-based for loop\n";
    for (std::string fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << "\n\n";

    std::cout << "[2] const 참조 사용 (복사 방지)\n";
    for (const std::string& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << "\n\n";

    std::cout << "[3] 수정 가능한 참조 사용 (원본 변경)";
    for (std::string& fruit : fruits) {
        fruit += "!";
    }
    for (const auto& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << "\n";

    return 0;
}
