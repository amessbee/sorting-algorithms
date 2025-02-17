project(sorting-algorithms)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/algorithms)

file(GLOB SOURCES
    src/main.cpp
    src/algorithms/*.cpp
)

add_executable(sorting-algorithms ${SOURCES})

enable_testing()

file(GLOB TEST_SOURCES
    tests/*.cpp
)

add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests sorting-algorithms)

add_test(NAME SortingAlgorithmsTests COMMAND run_tests)