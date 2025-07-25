#include <iostream>
#include <variant>
#include <string>

// 메시지 타입 정의
struct Ping { int id; };
struct Pong { std::string msg; };
struct Error { std::string reason; };

// 메시지를 variant로 정의
using Message = std::variant<Ping, Pong, Error>;

// 메시지 처리기
void handleMessage(const Message& msg) {
    std::visit([](const auto& m) {
        using T = std::decay_t<decltype(m)>;

        if constexpr (std::is_same_v<T, Ping>) {
            std::cout << "Ping 메시지! ID: " << m.id << "\n";
        } else if constexpr (std::is_same_v<T, Pong>) {
            std::cout << "Pong 메시지! 내용: " << m.msg << "\n";
        } else if constexpr (std::is_same_v<T, Error>) {
            std::cerr << "에러 발생! 이슈: " << m.reason << "\n";
        }
    }, msg);
}

int main() {
    Message m1 = Ping{42};
    Message m2 = Pong{"Hello"};
    Message m3 = Error{"Timeout"};

    handleMessage(m1);
    handleMessage(m2);
    handleMessage(m3);
}

/* std::visit */
// 정의 - std::visit(visitor, variant);
// - variant : 저장된 현재 타입에 따라 visitor 함수 호출함
// - visitor : 람다 함수 또는 함수 객체여야 하며, variant에 들어올 수 있는 모든 타입을 처리할 수 있어야 함
/* 예시
std::variant<int, std::string> v = 123;

std::visit([](const auto& val) {
    std::cout << "값: " << val << "\n";
}, v);
*/

/* std::holds_alternative<T>(variant) */
// 정의 - std::holds_alterative<T>(v)
// - v가 현재 T 타입을 보유하고 있는지를 판단해서 bool 값을 반환
/* 예시
if (std::holds_alternative<std::string>(v)) {
    std::cout << "문자열 타입입니다!\n";
}
- std::visit 보다 빠르게 타입을 체크하고 싶은 경우 유용
*/

/* decltype */
// 정의 - decltype(expr)
// - expr의 타입을 그대로 가져온다.
// - auto가 값만 가져오는 데 비해, decltype은 타입 정보 자체를 복사함
/* 예시
int x = 10;
decltype(x) y = 20;
*/
/* 실전 예시 (variant 내부)
std::visit([](const auto& m) {
    using T = decltype(m); // m이 어떤 타입인지 가져옴
}, msg);
*/

/* std::decay_t */
// 정의 - std::decay<T>::type과 동일, std::decay_t<T>
// T에서 다음을 제거한 기본 타입을 추출 (참조(&, &&), cosnt, volatile, 배열 -> 포인터, 함수 -> 함수 포인터)
/* 예시
template <typename T>
void foo(T&& x) {
    using CleanT = std::decay_t<T>;
    // CleanT는 T의 "순수한" 타입 (int&, const int 등 -> int)
}
*/
/* 실전예시
std::visit([](const auto& m) {
    using T = std::decay_t<decltype(m)>;
    if constexpr (std::is_name_v<T, Ping>) { ... }
    // 여기서 decltype(m)은 const Ping& 이지만 std::decay_t를 씌우면 Ping으로 변환되어
    // std::is_same_v<T, Ping>이 정확한 동작
});
*/

