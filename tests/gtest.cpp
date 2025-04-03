#define BOOST_TEST_MODULE test

#include <boost/test/included/unit_test.hpp>

#include <ip_filter.h>

BOOST_AUTO_TEST_SUITE(test_calc)

BOOST_AUTO_TEST_CASE(test_integral)
{
    BOOST_TEST(print_ip(int8_t{-1}) == "255");
    BOOST_TEST(print_ip(int16_t{0}) == "0.0");
    BOOST_TEST(print_ip(int32_t{2130706433}) == "127.0.0.1");
    BOOST_TEST(print_ip(int64_t{8875824491850138409}) == "123.45.67.89.101.112.131.41");
    BOOST_TEST(print_ip(std::string("Hello world!")) == "Hello world!");
    BOOST_TEST(print_ip(std::vector<uint16_t>{400, 300, 200, 100}) == "400.300.200.100");
    BOOST_TEST(print_ip(std::list<int>{100, 200, 300, 400}) == "100.200.300.400");
    BOOST_TEST(print_ip(std::make_tuple(100, 200, 300, 400)) == "100.200.300.400");
}

BOOST_AUTO_TEST_SUITE_END()