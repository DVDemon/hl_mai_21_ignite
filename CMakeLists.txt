cmake_minimum_required(VERSION 3.2)

project(hl_mai_20_ignite C CXX)


find_package(GTest REQUIRED)
find_package(Threads)

include_directories(${GTEST_INCLUDE_DIRS})


add_executable(ignite_test main.cpp)

add_executable(gtests tests.cpp)

target_compile_options(ignite_test PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(gtests PRIVATE -Wall -Wextra -pedantic -Werror )

target_link_libraries(ignite_test PRIVATE ${CMAKE_THREAD_LIBS_INIT} 
                                        "libignite-binary.so"
                                        "libignite-common.so"
                                        "libignite-thin-client.so")

target_link_libraries(gtests PRIVATE ${GTEST_LIBRARIES} 
                                     ${CMAKE_THREAD_LIBS_INIT} 
                                     "libignite-binary.so"
                                     "libignite-common.so"
                                     "libignite-thin-client.so")

set_target_properties(ignite_test 
                      gtests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)



set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT Dmitriy.Dzyuba@mts.ru)
include(CPack)

enable_testing()
add_test(gtests gtests)
