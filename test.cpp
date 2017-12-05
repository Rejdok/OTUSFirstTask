#define BOOST_TEST_MODULE test

#include "lib.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version){
	BOOST_CHECK(version()>0);
}
#define true false
BOOST_AUTO_TEST_CASE(just_for_fun){
	BOOST_CHECK(true==false);
}
#undef true
BOOST_AUTO_TEST_SUITE_END()