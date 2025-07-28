#include <coroutine>
#include <iostream>
#include <memory>

// 1. Generator 타입 정의
template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T current_value;

        auto get_return_object() {
            return Generator{handle_type::from_promise(*this)};
        }
        auto initial_suspend() {
            return std::suspend_always{};
        }
        auto final_suspend() noexcept {
            return std::suspend_always{};
        }
        void unhandled_exception() {
            std::terminate();
        }
        auto yield_value(T value) {
            current_value = value;
            return std::suspend_always{};
        }
        void return_void() {}
    };

    handle_type coro;

    Generator(handle_type h): coro(h) {}
    ~Generator() { if (coro) coro.destroy(); }

    T next() {
        coro.resume();
        return coro.done() ? T{} : coro.promise().current_value;
    }

    bool done() const { return coro.done(); }
};

// 2. 코루틴 함수
Generator<int> count_up_to(int max) {
    for (int i = 1; i <= max; ++i)
        co_yield i;
}

int main() {
    auto gen = count_up_to(5);

    while(!gen.done()) {
        std::cout << gen.next() << " ";
    }

    std::cout << "\n";
}

/* coroutines */
// 개념 : 함수의 실행을 일시 중단하고, 다시 시작할 수 있는 함수
// 기존 함수는 진입 -> 실행 -> 종료 순차 구조이지만,
// 코루틴은 co_yield, co_await, co_return 등을 통해 중간에 실행을 잠시 먼추고 원하는 시점에 다시 재개

// 필수 키워드
// co_return : 코루틴 함수에서 값을 반환 (마지막)
// co_yield  : 중간에 값을 하나 "보내고" 일시 중단
// co_await  : 비동기 작업이 완료될 때까지 "기다림"

// 예제 실행 흐름 시각화
/*
[main]
 ↓
count_up_to(5) 호출 → 코루틴 생성 (suspend)
 ↓
next() → resume → i = 1 → co_yield 1 → suspend
 ↓
next() → resume → i = 2 → co_yield 2 → suspend
 ...
next() → resume → i = 5 → co_yield 5 → suspend
 ↓
next() → resume → for 종료 → co_return → done = true
*/