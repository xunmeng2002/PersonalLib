SET(PROJECT_NAME "TestThrift")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

set(LibsPath "${CMAKE_SOURCE_DIR}/../Libs")
#set(VcpkgPth "D:/Github/vcpkg")
set(VcpkgPth "C:/Libs/vcpkg")

file(GLOB PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/ThriftProtocol/*.thrift")
message(STATUS "PROTOS:${PROTOS}")
foreach(PROTO ${PROTOS})
    #message(STATUS "thrift --gen cpp -out ./ThriftProtocol ${PROTO}")
    #execute_process(COMMAND thrift --gen cpp -out ./ThriftProtocol ${PROTO} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

set(CMAKE_TOOLCHAIN_FILE "${VcpkgPth}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
list(APPEND CMAKE_PREFIX_PATH "${VcpkgPth}/installed/x64-windows")
find_package(thrift REQUIRED)
find_package(ZLIB REQUIRED)

add_package(Src ./Src)
add_package(ThriftProtocol ./ThriftProtocol)

link_directories("${VcpkgPth}/installed/x64-windows/debug/lib")


# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} ${all_file})


# 链接 Thrift 库
target_link_libraries(${PROJECT_NAME} thrift::thrift thriftzmdd.lib ZLIB::ZLIB PersonalLib)

