#include <iostream>
#include <string>
#include <string_view>

// 문자열 처리 함수: 복사 없이 처리
void greet(std::string_view name) {
    std::cout << "Hello, " << name << "!\n";
}

// 슬라이싱 기능
void printFirstWord(std::string_view sentence) {
    size_t pos = sentence.find(' ');

    if(pos != std::string_view::npos) {
        std::cout << "첫 번째 단어: " << sentence.substr(0, pos) << "\n";
    } else {
        std::cout << "단어 전체: " << sentence << "\n";
    }
}

int main() {
    std::string name = "Alice";
    const char* cstr = "Bob";
    std::string_view sv = "Charlie";

    greet(name);        // std::string
    greet(cstr);        // const char*
    greet(sv);          // std::string_view

    printFirstWord("Modern C++ is powerful");
    printFirstWord("Hello");

    return 0;
}
