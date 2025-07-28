#include <iostream>

// consteval 함수: 반드시 컴파일 타임에만 실행 가능
consteval int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

// constinit 전역 변수: 반드시 constexpr로 초기화되어야 함
constinit int global_val = factorial(4);

int main() {
    std::cout << "global_val = " << global_val << "\n";

    // 런타임값으로는 consteval 함수 호출 불가
    // int x = 5;
    // int y = factorial(x); -> 컴파일 에러

    return 0;
}