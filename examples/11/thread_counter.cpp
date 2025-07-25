#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

void count_up(const std::string& name, int limit) {
    for(int i=0; i<limit; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << name << " count : " << i+1 << "\n";
    }
}

int main() {
    std::cout << "[main] 시작\n";

    std::thread t1(count_up, "Thread A", 5);
    std::thread t2(count_up, "Thread B", 5);

    t1.join();
    t2.join();

    std::cout << "[main] 종료\n";
    return 0;
}
