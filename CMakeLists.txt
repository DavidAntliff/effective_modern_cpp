cmake_minimum_required(VERSION 3.14)
project(effective_modern_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(effective_modern_cpp
        main.cc
        code.cc)

target_link_libraries(effective_modern_cpp LINK_PUBLIC pthread)


# Google Test
include(FetchContent)
FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
  	GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()
#find_package(GTest REQUIRED)

add_executable(tests
        code.cc
        tests.cc)

# -Wno-missing-braces due to clang bug: https://stackoverflow.com/questions/13905200/is-it-wise-to-ignore-gcc-clangs-wmissing-braces-warning
target_compile_options(tests PRIVATE -Wall -Wextra -Wno-missing-braces -Wno-missing-field-initializers)

target_link_libraries(tests LINK_PUBLIC gtest gtest_main)

gtest_discover_tests(tests)
