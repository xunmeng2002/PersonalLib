


add_module(TestCommon ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/TestCommon)
target_link_libraries(TestCommon PUBLIC Core Network)


add_application(TestMD5         ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestMD5)
add_application(TestCore        ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestCore)
add_application(TestClient      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestClient)
add_application(TestServer      ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestServer)

target_link_libraries(TestMD5 PRIVATE Core)
target_link_libraries(TestCore PRIVATE Core)
target_link_libraries(TestClient PRIVATE TestCommon)
target_link_libraries(TestServer PRIVATE TestCommon)


SET(APIVersion "6.7.9")
add_module(CtpWrapper ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/CtpWrapper)
target_include_directories(CtpWrapper PUBLIC ${CMAKE_SOURCE_DIR}/../Libs/CTP/${APIVersion}/include)
target_link_libraries(CtpWrapper PUBLIC Core Network Serialization thostmduserapi_se thosttraderapi_se)
