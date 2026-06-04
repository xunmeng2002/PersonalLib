cmake_minimum_required(VERSION 3.20)
SET(PROJECT_NAME "PersonLib")
project(${PROJECT_NAME})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(BUILD_TEST_PROJECT 1)

add_definitions(-DUNICODE -D_UNICODE)
message("CMAKE_BUILD_TYPE:" ${CMAKE_BUILD_TYPE})
message("CMAKE_SYSTEM_NAME:" ${CMAKE_SYSTEM_NAME})
message("CMAKE_CL_64:" ${CMAKE_CL_64})
IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
	#string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
	#string(REPLACE "/MDd" "/MTd" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
	add_definitions("-DWINDOWS")
	add_definitions("-DPERSONAL_LIB")
	add_definitions("-D_CRT_SECURE_NO_WARNINGS")
	add_definitions("-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING")
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	IF(CMAKE_BUILD_TYPE MATCHES "Debug")
		#list(APPEND CMAKE_CXX_FLAGS "-fsanitize=address")
	ENDIF()
	add_definitions("-DLINUX")
ENDIF()
message("CMAKE_CXX_FLAGS:" ${CMAKE_CXX_FLAGS})
message("CMAKE_CXX_FLAGS_RELEASE:" ${CMAKE_CXX_FLAGS_RELEASE})
message("CMAKE_CXX_FLAGS_DEBUG:" ${CMAKE_CXX_FLAGS_DEBUG})


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)   # exe, dll (Windows)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)   # .so, .dylib (·Ç Windows)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)   # .lib, .a

macro(add_module module_name src_dir)
    file(GLOB_RECURSE module_sources CONFIGURE_DEPENDS "${src_dir}/*.cpp" "${src_dir}/*.c" "${src_dir}/*.cu")
    add_library(${module_name} STATIC ${module_sources})
    target_include_directories(${module_name} PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/Source)
endmacro()

add_module(Core				${CMAKE_SOURCE_DIR}/Source/Core)
add_module(Network			${CMAKE_SOURCE_DIR}/Source/Network)
add_module(Serialization	${CMAKE_SOURCE_DIR}/Source/Serialization)

target_link_libraries(Network PUBLIC Core)



string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d-%H%M%S")
message("Build timestamp is ${BUILD_TIMESTAMP}")

#add_subdirectory(Target)
add_subdirectory(Test)
