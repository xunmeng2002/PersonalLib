
add_static_module(TestCommon ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/TestCommon)
target_link_libraries(TestCommonStatic PUBLIC CoreStatic NetworkStatic)


add_application(TestMD5         ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestMD5)
add_application(TestCore        ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestCore Static)
add_application(TestClient      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestClient STATIC)
add_application(TestServer      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestServer STATIC)
target_link_libraries(TestMD5 PRIVATE Core)
target_link_libraries(TestCore PRIVATE CoreStatic)
target_link_libraries(TestClient PRIVATE TestCommonStatic)
target_link_libraries(TestServer PRIVATE TestCommonStatic)

