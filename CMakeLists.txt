cmake_minimum_required(VERSION 3.14)
project (modern_cpp_series)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 컴파일러 경고 설정 (선택사항)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# example 디렉토리 빌드 대상 추가
add_subdirectory(examples/11)
add_subdirectory(examples/17)
add_subdirectory(examples/20)
