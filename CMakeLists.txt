cmake_minimum_required(VERSION 3.8)
# https://lld.llvm.org/WebAssembly.html

project(wasm-example)

include(FetchContent)


message(STATUS "******* ${CMAKE_CXX_COMPILER_VERSION}")

Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  serverless-sdk
  GIT_REPOSITORY https://github.com/edgeMicroservice/wasm-serverless-cpp-sdk.git
  GIT_TAG v1.0.0
  GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(serverless-sdk)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_SOURCE_DIR}/main.cpp
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES COMPILE_FLAGS "-fno-exceptions"
  SUFFIX ".wasm"
)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,--allow-undefined")

target_link_libraries(${PROJECT_NAME}
  wasm-serverless
)
