cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

add_library(test_version test.cpp)

set_target_properties(
	helloworld_cli helloworld test_version PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(
	test_version PROPERTIES
	COMPILE_DEFENITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
	helloworld_cli
	helloworld
)

target_link_libraries(
	test_version
	${Boost_LIBRARES}
	helloworld
)

enable_testing()
add_test(test_version test_version)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPAC_GENERAOR DEB)

set(CPACK_PAKGE_VERSION_MAJOR "${PAKGE_VERSION_MAJOR}")
set(CPACK_PAKGE_VERSION_MINOR "${PAKGE_VERSION_MINOR}")
set(CPACK_PAKGE_VERSION_PATCH "${PAKGE_VERSION_PATCH}")
set(CPAK_PACKAGE_CONTACT lvbnu@yandex.ru)

include(CPack)

