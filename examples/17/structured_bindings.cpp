#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::cout << "[1] std::pair 구조 분해\n";
    std::pair<std::string, int> p = {"apple", 10};
    auto [fruit, quantity] = p;
    std::cout << fruit << "-" << quantity << "\n\n";

    std::cout << "[2] std::tuple 구조 분해\n";
    std::tuple<std::string, int, double> t = {"banana", 5, 3.14};
    auto [name, count, weight] = t;
    std::cout << name << ", " << count << ", " << weight << "\n\n";

    std::cout << "[3] map 반복 시 구조 문해\n";
    std::map<std::string, int> m = {{"kim", 30}, {"lee", 20}};
    for(const auto [key, value] : m) {
        std::cout << key << " => " << value << "\n";
    }
    std::cout << "\n";

    std::cout << "[4] 사용자 정의 구조체 분해\n";
    Person p1 = {"Choi",25};
    auto [person_name, person_age] = p1;
    std::cout << person_name << "is " << person_age << " yelos old.\n";

    return 0;
}