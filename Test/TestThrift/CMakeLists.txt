SET(PROJECT_NAME "TestThrift")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})


file(GLOB PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/ThriftProtocol/*.thrift")
message(STATUS "PROTOS:${PROTOS}")
foreach(PROTO ${PROTOS})
    #message(STATUS "thrift --gen cpp -out ./ThriftProtocol ${PROTO}")
    #execute_process(COMMAND thrift --gen cpp -out ./ThriftProtocol ${PROTO} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

set(CMAKE_TOOLCHAIN_FILE "C:/Libs/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
list(APPEND CMAKE_PREFIX_PATH "C:/Libs/vcpkg/installed/x64-windows")
find_package(thrift REQUIRED)
find_package(ZLIB REQUIRED)

add_package(Src ./Src)
add_package(ThriftProtocol ./ThriftProtocol)

include_package(PersonalLibHeader ${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/include)

link_directories("C:/Libs/vcpkg/installed/x64-windows/debug/lib")


# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} ${all_file})


if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	find_library(PersonnalLib PersonnalLib ${CMAKE_SOURCE_DIR}/out/build/x64-Debug/Target/PersonnalLib)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:PersonalLib>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>" COMMENT "Copying PersonalLib.dll DLL...")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
endif()

# 链接 Thrift 库
target_link_libraries(${PROJECT_NAME} thrift::thrift thriftzmdd.lib ZLIB::ZLIB PersonalLib)

