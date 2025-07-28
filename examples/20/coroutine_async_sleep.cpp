#include <coroutine>
#include <chrono>
#include <iostream>
#include <thread>

struct SleepAwaiter {
    int ms;

    // 1. 작업이 즉시 완료했는가?
    bool await_ready() const noexcept {
        return false; // 무조건 suspend
    }

    // 2. suspend 됐을 때 할 일 (별도 쓰레드에서 재개 예약)
    void await_suspend(std::coroutine_handle<> h) const {
        std::thread([h, ms = ms]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            h.resume();
        }).detach();
    }

    // 3. resume 후의 리턴값
    void await_resume() const noexcept {}
};

// Task 리턴 타입
struct Task {
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };
};

// 코루틴 함수
Task async_function() {
    std::cout << "1초 대기 시작\n";
    co_await SleepAwaiter{1000}; // 1초 기다리기
    std::cout << "1초 후 실행됨!\n";
}

int main() {
    async_function(); // 호출 시 즉시 시작
    std::this_thread::sleep_for(std::chrono::seconds(2)); // main 종료 방지
}