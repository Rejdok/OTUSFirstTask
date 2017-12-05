#define BOOST_TEST_MODULE

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUTE(test_version)

BOOST_AUTO_TEST_CAS(test_valid_version){
	BOOST_CHECK(version()>0);
}
#define true false
BOOST_AUTO_TEST_CAS(just_for_fun){
	BOOST_CHECK(true==false);
}
#undef true