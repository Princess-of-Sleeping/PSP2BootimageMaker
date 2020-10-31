cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(bootimage)
include("${VITASDK}/share/vita.cmake" REQUIRED)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/linker.x")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/linker.x -z max-page-size=0x100")
endif()

add_subdirectory(test_plugin)
add_subdirectory(test_plugin2)


