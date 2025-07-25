#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;

    Item(const std::string& n) : name(n) {
        std::cout << "생성자: " << name << "\n";
    }

    // 복사 생성자
    Item(const Item& other) : name(other.name) {
        std::cout << "복사 생성자: " << name << "\n";
    }

    // 이동 생성자
    Item(Item&& other) noexcept : name(std::move(other.name)) {
        std::cout << "이동 생성자: " << name << "\n";
    }

    ~Item() {
        std::cout << "소멸자: " << name << "\n";
    }
};

int main() {
    std::vector<Item> items;

    std::cout << "\n[1] 복사로 삽입\n";
    Item a("Apple");
    items.push_back(a); // 복사 발생

    std::cout << "\n[2] 이동으로 삽입\n";
    Item b("Banana");
    items.push_back(std::move(b));

    std::cout << "\n[3] 임시 객체 삽입\n";
    items.push_back(Item("Cherry"));
}
