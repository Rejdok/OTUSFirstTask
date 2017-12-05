cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

add_executable(test_version test.cpp)

set_target_properties(
	helloworld_cli helloworld test_version PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_compile_definitions(
	test_version
	PRIVATE "BOOST_TEST_DYN_LINK=1"
)
target_link_libraries(
	helloworld_cli
	helloworld
)

target_link_libraries(
	test_version
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Rejdok")
set(CPAK_PACKAGE_CONTACT "lvbnu@yandex.ru")
include(CPack)


enable_testing()
add_test(test_version test_version)
