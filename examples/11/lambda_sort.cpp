#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> names = {"kims", "lee", "park", "choi"};

    std::cout << "[1] 기본 람다 정렬 (길이 오름차순)\n";
    std::sort(names.begin(), names.end(),[](const std::string& a, const std::string& b){
        return a.size() < b.size();
    });

    for(const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << "\n\n";

    std::cout << "[2] 외부 기준값 기반 정렬 (길이 기준값과의 차이)\n";
    int target = 4;

    std::sort(names.begin(), names.end(), [target](const std::string& a, const std::string& b){
        return std::abs((int)a.size() - target) < std::abs((int)b.size() - target);
    });

    for(const auto& name : names)
        std::cout << name << " ";
    std::cout << "\n\n";

    std::cout << "[3] 캡처 by refenece (외부 변수 수정)\n";
    int counter = 0;
    std::for_each(names.begin(), names.end(), [&counter](const std::string& name){
        std::cout << ++counter << ": " << name << "\n";
    });

    return 0;
}
