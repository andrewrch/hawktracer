cmake_minimum_required(VERSION 3.1)

project(HawkTracer
    VERSION 0.5.0)

option(ENABLE_ASAN "Enable address sanitizer" OFF)
option(ENABLE_TESTS "Enable unit tests" OFF)
option(ENABLE_CODE_COVERAGE "Enable code coverage" OFF)
option(ENABLE_BENCHMARKS "Enable benchmarks" OFF)
option(ENABLE_EXAMPLES "Enable examples" OFF)
option(ENABLE_DOC "Build documentation" ON)

option(BUILD_STATIC_LIB "Build static hawktracer library" OFF)

option(ENABLE_MAINTAINER_MODE "Enables maintainer mode. Overrides some flags
    (e.g. ENABLE_TESTS, ENABLE_CODE_COVERAGE, ENABLE_BENCHMARKS)")

option(ENABLE_RELEASE_MODE "Enables release mode. This flag should be used
    to compile and release product.")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PLATFORM FEATURES
include(platform_features)
define_platform_feature(CPU_USAGE "cpu_usage.c")

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_STANDARD 99)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(ENABLE_MAINTAINER_MODE)
    set(ENABLE_TESTS ON)
    set(ENABLE_CODE_COVERAGE ON)
    set(ENABLE_BENCHMARKS ON)
    set(ENABLE_EXAMPLES ON)
endif(ENABLE_MAINTAINER_MODE)

if(ENABLE_RELEASE_MODE)
    set(ENABLE_TESTS ON)
    set(ENABLE_BENCHMARKS ON)
    set(ENABLE_EXAMPLES ON)
endif(ENABLE_RELEASE_MODE)

include(warnings)

if(ENABLE_ASAN)
    include(asan)
endif(ENABLE_ASAN)

if(ENABLE_CODE_COVERAGE)
    include(coverage)
endif(ENABLE_CODE_COVERAGE)

if(ENABLE_DOC)
    include(documentation)
endif(ENABLE_DOC)

add_subdirectory(lib)
add_subdirectory(parser)
add_subdirectory(client)

add_subdirectory(tools_integration)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(ENABLE_TESTS)

if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif(ENABLE_EXAMPLES)
install(DIRECTORY examples DESTINATION .)

if(ENABLE_BENCHMARKS)
    add_subdirectory(benchmarks)
endif(ENABLE_BENCHMARKS)

include(packager)

