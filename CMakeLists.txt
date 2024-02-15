cmake_minimum_required(VERSION 3.8)
# https://lld.llvm.org/WebAssembly.html

# Give the project a name
project(wasm-example)

# Use CMake build FetchContent
include(FetchContent)

# Report the version of CMake
message(STATUS "******* ${CMAKE_CXX_COMPILER_VERSION}")

# Make FETCHCONTENT_QUIET false so it's verbose
Set(FETCHCONTENT_QUIET FALSE)


# The dependencies
FetchContent_Declare(
  serverless-sdk
  GIT_REPOSITORY https://github.com/edgeMicroservice/wasm-serverless-cpp-sdk.git
  GIT_TAG v2.0.0
  GIT_PROGRESS TRUE
)

# Make dependencies avaiable
FetchContent_MakeAvailable(serverless-sdk)

# Create the WASM binary
add_executable(${PROJECT_NAME})

#Set targets
target_sources(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# Disable C++ exceptions, and set the filename extension to .wasnm
set_target_properties(${PROJECT_NAME}
  PROPERTIES COMPILE_FLAGS "-fno-exceptions"
  SUFFIX ".wasm"
)

# Allow undefined
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--allow-undefined")

# Link to WASM server library
target_link_libraries(${PROJECT_NAME}
  wasm-serverless
)
