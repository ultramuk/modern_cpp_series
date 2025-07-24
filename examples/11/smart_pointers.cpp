#include <iostream>
#include <string>
#include <memory>

class Resource {
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Resource [" << name_ << "] acquired\n";
    }
    ~Resource() {
        std::cout << "Resource [" << name_ << "] destroyed\n";
    }
    void use() const {
        std::cout << "Using Resource [" << name_ << "]\n";
    }

private:
    std::string name_;
};

// unique_ptr<T>: 단독 소유 / 복사 불가(std::move로만 이동) / 성능 우수, 소유 명확
void unique_ptr_demo() {
    std::cout << "\n[unique_ptr 데모]\n";
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>("res1");
    res1->use();

    std::unique_ptr<Resource> res2 = std::move(res1);
    if(!res1) std::cout << "res1은 더이상 유효하지 않음\n";
    res2->use();
}

// shared_ptr<T>: 공유 소유 / 복사 가능 / 참조 카운트 기반 자동 해제
void shared_ptr_demo() {
    std::cout << "\n[shared_ptr 데모]\n";
    std::shared_ptr<Resource> resA = std::make_shared<Resource>("resA");
    {
        std::shared_ptr<Resource> resB = resA;
        std::cout << "공유 카운트: " << resA.use_count() << "\n";
        resB->use();
    }
    std::cout << "공유 카운트: " << resA.use_count() << "\n";
    resA->use();
}

int main() {
    unique_ptr_demo();
    shared_ptr_demo();

    return 0;
}

