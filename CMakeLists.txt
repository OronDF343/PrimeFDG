cmake_minimum_required(VERSION 3.0.0)
project(PrimeFDG VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-march=sandybridge)
add_compile_options(-mtune=znver1)
add_compile_options(-fopenmp)

add_executable(PrimeFDG
    src/bitarray.c
    src/cpuid.c
    src/io.c
    src/pevents.cpp
    src/pevents_c.cpp
    src/pfdg.c
	src/cli.c
    src/main.c
)
target_link_libraries(PrimeFDG PRIVATE m)
target_link_libraries(PrimeFDG PRIVATE gomp)
target_link_libraries(PrimeFDG PRIVATE pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
