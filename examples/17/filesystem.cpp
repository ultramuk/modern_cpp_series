#include <iostream>
#include <filesystem>

void listFilesInDirectory(const std::filesystem::path& dirPath) {
    if(!std::filesystem::exists(dirPath)) {
        std::cerr << "경로가 존재하지 않습니다: " << dirPath << "\n";
        return;
    }

    if(!std::filesystem::is_directory(dirPath)) {
        std::cerr << "디렉토리가 아닙니다: " << dirPath << "\n";
        return;
    }

    std::cout << "[디렉토리 내 파일 목록: " << dirPath << "]\n";

    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        std::cout << (std::filesystem::is_directory(entry) ? "[DIR] " : "      ");
        std::cout << entry.path().filename() << "\n";
    }
}

int main() {
    std::filesystem::path dir = ".";
    listFilesInDirectory(dir);

    return 0;
}
