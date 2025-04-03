#include <iostream>
#include <ip_filter.h>

int main()
{
    std::cout << print_ip(int8_t{-1}) << std::endl;
    std::cout << print_ip(int16_t{0}) << std::endl;
    std::cout << print_ip(int32_t{2130706433}) << std::endl;
    std::cout << print_ip(int64_t{8875824491850138409}) << std::endl;
    std::cout << print_ip(std::string("Hello world!")) << std::endl;
    std::cout << print_ip(std::vector<uint16_t>{400, 300, 200, 100}) << std::endl;
    std::cout << print_ip(std::list<int>{100, 200, 300, 400}) << std::endl;
    std::cout << print_ip(std::make_tuple(100, 200, 300, 400)) << std::endl;
    return EXIT_SUCCESS;
}
