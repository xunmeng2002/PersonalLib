SET(PROJECT_NAME "TestMD5")
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
add_package(MD5 ${CMAKE_SOURCE_DIR}/Source/MD5)

add_executable(${PROJECT_NAME} ${all_file})
