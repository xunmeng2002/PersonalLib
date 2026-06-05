cmake_minimum_required(VERSION 3.20)
SET(PROJECT_NAME "PersonalLib")
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)

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

macro(add_module name include_dir src_dir)
    file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "${src_dir}/*.cpp" "${src_dir}/*.c" "${src_dir}/*.cu")
    add_library(${name} STATIC ${src_files})
    target_include_directories(${name}
        PUBLIC
            $<BUILD_INTERFACE:${include_dir}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${src_dir}/../..
    )
endmacro()
macro(add_application name include_dir src_dir)
    file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "${src_dir}/*.cpp" "${src_dir}/*.c" "${src_dir}/*.cu")
    add_executable(${name} ${src_files})
    target_include_directories(${name}
        PUBLIC
            ${include_dir}
        PRIVATE
            ${src_dir}/..
    )
endmacro()
macro(copy_config_file name config_file)
    add_custom_command(TARGET ${name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${config_file}
            $<TARGET_FILE_DIR:${name}>
        COMMENT "Copying config file ${config_file} to output directory"
    )
endmacro()

add_module(Core				${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Core)
add_module(Network			${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Network)
add_module(Serialization	${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Serialization)

target_link_libraries(Network PUBLIC Core)

option(BUILD_TESTS "Build test projects" ON)
if(BUILD_TESTS)
    add_subdirectory(Test)
endif()

string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d-%H%M%S")
message("Build timestamp is ${BUILD_TIMESTAMP}")

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS Core Network Serialization
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    "include(CMakeFindDependencyMacro)\n"
    "# Add find_dependency calls if your library has dependencies\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Targets.cmake\")\n"
    "check_required_components(\"${PROJECT_NAME}\")\n"
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)