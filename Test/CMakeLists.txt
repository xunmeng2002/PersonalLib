
macro(add_test_executable target_name src_dir)
    file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${src_dir}/*.cpp" "${src_dir}/*.c" "${src_dir}/*.cu")
    add_executable(${target_name} ${sources})
    target_include_directories(${target_name} PRIVATE ${src_dir})
endmacro()

add_test_executable(TestMD5 ${CMAKE_SOURCE_DIR}/Test/TestMD5)
add_test_executable(TestPersonalLib ${CMAKE_SOURCE_DIR}/Test/TestPersonalLib)
add_test_executable(TestClient ${CMAKE_SOURCE_DIR}/Test/TestClient)
add_test_executable(TestServer ${CMAKE_SOURCE_DIR}/Test/TestServer)

target_link_libraries(TestMD5 PRIVATE Core)
target_link_libraries(TestPersonalLib PRIVATE Core)
target_link_libraries(TestClient PRIVATE Core Network)
target_link_libraries(TestServer PRIVATE Core Network)

