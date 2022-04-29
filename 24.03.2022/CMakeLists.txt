cmake_minimum_required(VERSION 3.0.0)
project(24.03.2022 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(24.03.2022 main.cpp test.asm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
