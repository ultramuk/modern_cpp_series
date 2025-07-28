#include <iostream>
#include <concepts>
#include <string>

// Concept 정의: Addable
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

// 템플릿 함수: Add
template<Addable T>
T Add(T a, T b) {
    return a + b;
}

int main() {
    int x = Add(3, 5);
    double y = Add(2.5, 4.1);
    std::string z = Add(std::string("Hi, "), std::string("CPP!"));

    std::cout << x << "\n";
    std::cout << y << "\n";
    std::cout << z << "\n";

    // 아래 코드는 컴파일 에러 발생 (Addable이 아님)
    // struct NotAddable();
    // Add(NotAddable{}, NotAddable{});

    return 0;
}

// concepts: 템플릿 파라미터에 타입 제약 조건을 명시적으로 선언할 수 있게 해주는 문법

// int, double, std::string은 모두 + 연산이 가능하기 때문에 통과이지만
// NotAddable 타입은 + 연산이 정의되지 않았기 때문에 컴파일 에러 발생
// (개발자가 의도하지 않은 타입이 들어오지 않도록 방지)
