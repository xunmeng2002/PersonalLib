


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
target_link_directories(CtpWrapper PUBLIC ${CMAKE_SOURCE_DIR}/../Libs/CTP/${APIVersion}/win64)
target_link_libraries(CtpWrapper PUBLIC Core Network Serialization thostmduserapi_se thosttraderapi_se)

set(CTP_DLL_DIR ${CMAKE_SOURCE_DIR}/../Libs/CTP/${APIVersion}/win64)
set(CTP_DLLS ${CTP_DLL_DIR}/thostmduserapi_se.dll ${CTP_DLL_DIR}/thosttraderapi_se.dll)


add_application(TestCtpMdApi		${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestCtpMdApi)
add_application(TestCtpTraderApi	${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/TestCtpTraderApi)
target_link_libraries(TestCtpMdApi PRIVATE CtpWrapper)
target_link_libraries(TestCtpTraderApi PRIVATE CtpWrapper)


add_custom_command(TARGET CtpWrapper POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CTP_DLLS}
        ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>
    COMMENT "Copying CTP DLLs to binary directory")
copy_config_file(TestCtpMdApi ${CMAKE_CURRENT_SOURCE_DIR}/src/CtpWrapper/CtpAccountInfo.json)
