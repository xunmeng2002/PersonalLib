SET(PROJECT_NAME "TestPersonalLib")
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)

add_executable(${PROJECT_NAME} ${all_file})

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${PROJECT_NAME} PersonalLib.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${PROJECT_NAME} pthread PersonalLib)
endif()
