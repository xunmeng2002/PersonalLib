SET(PROJECT_NAME "TestPersonalLib")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
include_package(PersonalLibHeader ${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/include)
link_directories(${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/win64)

add_executable(${PROJECT_NAME} ${all_file})

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${PROJECT_NAME} PersonalLib.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${PROJECT_NAME} pthread PersonalLib)
endif()
