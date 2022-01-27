cmake_minimum_required(VERSION 3.0)
project(NoRevenge VERSION 1.0 LANGUAGES C)

if (DEBUG)
  set(CMAKE_C_FLAGS "-g")
endif ()

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/raylib/)
include_directories(${PROJECT_SOURCE_DIR}/vendor/raylib/src)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} raylib)

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${PROJECT_SOURCE_DIR}/res
          ${PROJECT_BINARY_DIR}/res)
