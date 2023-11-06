cmake_minimum_required(VERSION 3.4.1)

set(TD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../td)
if (CMAKE_CROSSCOMPILING)
  list(APPEND CMAKE_FIND_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/third_party/crypto/${ANDROID_ARCH_NAME}")
endif()
add_subdirectory(${TD_DIR} td)

if (CMAKE_CROSSCOMPILING)
  string(APPEND CMAKE_CXX_FLAGS " -std=c++14 -fno-omit-frame-pointer -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti")
  string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--gc-sections -Wl,--exclude-libs,ALL")

  add_library(tdjsonandroid SHARED td_json.cpp)

  target_link_libraries(tdjsonandroid PRIVATE Td::TdJsonStatic tdcore)

  add_custom_command(TARGET tdjsonandroid POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rename $<TARGET_FILE:tdjsonandroid> $<TARGET_FILE:tdjsonandroid>.debug
    COMMAND ${CMAKE_STRIP} --strip-debug --strip-unneeded $<TARGET_FILE:tdjsonandroid>.debug -o libtdjson.so)
endif()


