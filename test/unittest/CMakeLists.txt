cmake_minimum_required(VERSION 3.20)

find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS "*.cpp")

add_executable(UnitTests ${test_sources})

target_link_libraries(UnitTests PRIVATE
    GTest::gtest
    GTest::gtest_main
    Core
    Serialization
)

target_include_directories(UnitTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

set_target_properties(UnitTests PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
)
