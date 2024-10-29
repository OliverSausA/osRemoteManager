#define BOOST_TEST_MODULE MainTestModule
#include <boost/test/included/unit_test.hpp>

#include "Models/DeviceTests.h"

BOOST_AUTO_TEST_SUITE(MyTestSuite)

BOOST_AUTO_TEST_CASE(AddTwoPositiveNumbers)
{
  BOOST_TEST( 3 + 3 == 6 );
}

BOOST_AUTO_TEST_SUITE_END()
