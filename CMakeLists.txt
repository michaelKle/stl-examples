cmake_minimum_required(VERSION 3.25)
project(STL)

find_package(Threads REQUIRED)

add_executable(thread-naive
    src/thread-naive.cpp
)
set_property(TARGET thread-naive PROPERTY CXX_STANDARD 11)
target_link_libraries(thread-naive PRIVATE Threads::Threads)

add_executable(thread-classic
    src/thread-classic.cpp
)
set_property(TARGET thread-classic PROPERTY CXX_STANDARD 14)
target_link_libraries(thread-classic PRIVATE Threads::Threads)

add_executable(thread-cpp20
    src/thread-cpp20.cpp
)
set_property(TARGET thread-cpp20 PROPERTY CXX_STANDARD 20)
target_link_libraries(thread-cpp20 PRIVATE Threads::Threads)
