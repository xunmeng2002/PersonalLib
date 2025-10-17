SET(PROJECT_NAME "TestPersonalLib")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
include_package(PersonalLibHeader ${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/include)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	link_directories(${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/win64)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	link_directories(${CMAKE_SOURCE_DIR}/../Libs/PersonalLib/linux)
endif()

add_executable(${PROJECT_NAME} ${all_file})

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${PROJECT_NAME} PersonalLib.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${PROJECT_NAME} pthread PersonalLib)
endif()


if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "$<TARGET_FILE:PersonalLib>" 
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/$<TARGET_FILE_NAME:PersonalLib>"
    COMMENT "Copying PersonalLib.dll DLL...")
endif()
