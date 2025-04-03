cmake_minimum_required(VERSION 3.10.0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION} LANGUAGES CXX)

option(WITH_GTEST_TEST "Whether to build GTEST test" ON)

configure_file(version.h.in version.h)

add_executable(ip_filter 
    src/ip_filter.cpp )

target_include_directories(ip_filter PUBLIC
    inc/
)

if(WITH_GTEST_TEST)
    find_package(GTest REQUIRED)
    add_executable(gtest tests/gtest.cpp)

    

    target_include_directories(gtest PUBLIC inc/)

    set_target_properties(gtest PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(gtest GTest::GTest)

    find_package(GTest REQUIRED)
endif()

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )

else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    if(WITH_GTEST_TEST)
    target_compile_options(gtest PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    endif()
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GTEST_TEST)
    enable_testing()
    add_test(gtest gtest)
endif()