


add_module(TestCommon ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/TestCommon)
target_link_libraries(TestCommon PUBLIC Core Network)

macro(add_test_executable target_name include_dir src_dir)
    file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "${src_dir}/*.cpp" "${src_dir}/*.c" "${src_dir}/*.cu")
    add_executable(${target_name} ${src_files})
    target_include_directories(${target_name} PUBLIC ${include_dir} PRIVATE ${src_dir}/..)
endmacro()

add_test_executable(TestMD5         ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestMD5)
add_test_executable(TestCore        ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestCore)
add_test_executable(TestClient      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestClient)
add_test_executable(TestServer      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestServer)

target_link_libraries(TestMD5 PRIVATE Core)
target_link_libraries(TestCore PRIVATE Core)
target_link_libraries(TestClient PRIVATE TestCommon)
target_link_libraries(TestServer PRIVATE TestCommon)

