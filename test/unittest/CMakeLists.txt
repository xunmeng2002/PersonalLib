cmake_minimum_required(VERSION 3.20)

# Google Test: 使用 FetchContent 从 GitHub 直接拉取源码编译
# 不依赖 vcpkg（虽然项目配置了 vcpkg.json，但国内网络下载 vcpkg 自身的
# 构建工具 cmake 时会遇到 SSL 问题，故 gtest 采用 FetchContent 方案）
include(FetchContent)
cmake_policy(SET CMP0135 NEW)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(BUILD_GMOCK OFF CACHE BOOL "Disable gmock" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS "*.cpp")

add_executable(UnitTests ${test_sources})

target_link_libraries(UnitTests PRIVATE
    GTest::gtest
    GTest::gtest_main
    Core
)

target_include_directories(UnitTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

set_target_properties(UnitTests PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
)

copy_dll_file(UnitTests)

gtest_discover_tests(UnitTests)
