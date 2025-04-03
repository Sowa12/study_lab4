#define BOOST_TEST_MODULE test

#include <gtest/gtest.h>

#include <ip_filter.h>

TEST(Push5test, Positive)
{
    EXPECT_EQ(print_ip(int8_t{-1}) , "255");
    EXPECT_EQ(print_ip(int16_t{0}) , "0.0");
    EXPECT_EQ(print_ip(int32_t{2130706433}) , "127.0.0.1");
    EXPECT_EQ(print_ip(int64_t{8875824491850138409}) , "123.45.67.89.101.112.131.41");
    EXPECT_EQ(print_ip(std::string("Hello world!")) , "Hello world!");
    EXPECT_EQ(print_ip(std::vector<uint16_t>{400, 300, 200, 100}) , "400.300.200.100");
    EXPECT_EQ(print_ip(std::list<int>{100, 200, 300, 400}) , "100.200.300.400");
    EXPECT_EQ(print_ip(std::make_tuple(100, 200, 300, 400)) , "100.200.300.400");
}

int main()
{

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}