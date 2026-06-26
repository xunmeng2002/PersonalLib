cmake_minimum_required(VERSION 3.20)
SET(PROJECT_NAME "PersonalLib")
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(GenerateExportHeader)
include(submodules/CMakeCommon/CMakeCommon.cmake)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_compile_options(/std:c++20)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_compile_options(-std=c++20)
endif()
#set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_VERBOSE_MAKEFILE ON)
add_definitions(-DUNICODE -D_UNICODE)


IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    add_definitions(-DWINDOWS -D_CRT_SECURE_NO_WARNINGS -D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
	add_compile_options(
        $<$<CONFIG:Debug>:/Od>
        $<$<CONFIG:Debug>:/Zi>
        $<$<CONFIG:Release>:/O2>
        $<$<CONFIG:RelWithDebInfo>:/O2>
        $<$<CONFIG:RelWithDebInfo>:/Zi>
        $<$<CONFIG:MinSizeRel>:/O1>)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	add_definitions("-DLINUX")
    add_compile_options(
        $<$<CONFIG:Debug>:-O0 -g -ggdb>
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:RelWithDebInfo>:-O2 -g>
        $<$<CONFIG:MinSizeRel>:-Os>)
    add_compile_definitions(
        $<$<CONFIG:Debug>:_DEBUG>
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:RelWithDebInfo>:NDEBUG>
        $<$<CONFIG:MinSizeRel>:NDEBUG>)
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -ggdb")
    #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
    #list(APPEND CMAKE_CXX_FLAGS_DEBUG "-fsanitize=address")
ENDIF()
message("CMAKE_BUILD_TYPE:" ${CMAKE_BUILD_TYPE})
message("CMAKE_SYSTEM_NAME:" ${CMAKE_SYSTEM_NAME})
message("CMAKE_CL_64:" ${CMAKE_CL_64})
message("CMAKE_CXX_FLAGS:" ${CMAKE_CXX_FLAGS})
message("CMAKE_CXX_FLAGS_RELEASE:" ${CMAKE_CXX_FLAGS_RELEASE})
message("CMAKE_CXX_FLAGS_DEBUG:" ${CMAKE_CXX_FLAGS_DEBUG})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/$<CONFIG>)




add_template_library(TemplateLib    ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_static_module(Core              ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Core)
add_static_module(Network           ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Network)
add_static_module(Serialization     ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Serialization)
target_link_libraries(NetworkStatic PUBLIC CoreStatic)

add_shared_module(Core				${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Core)
add_shared_module(Network			${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Network)
add_shared_module(Serialization	    ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Serialization)
target_compile_definitions(Serialization PRIVATE JSON_DLL_BUILD)
target_link_libraries(Network PUBLIC Core)


option(BUILD_TESTS "Build test projects" ON)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()

string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d-%H%M%S")
message("Build timestamp is ${BUILD_TIMESTAMP}")

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS 
    Core Network Serialization
    CoreStatic NetworkStatic SerializationStatic
    EXPORT ${PROJECT_NAME}Targets
    #CONFIGURATIONS Release
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT ${PROJECT_NAME}Targets
    NAMESPACE ${PROJECT_NAME}::
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
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Targets.cmake\")\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)