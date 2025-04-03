#include <list>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>
#include <cstdint>
#include <print_tuple.h>

template <typename T>
struct is_std_vector
{
    static const bool value = false;
};

template <typename T>
struct is_std_vector<std::vector<T>>
{
    static const bool value = true;
};

template <typename T>
struct is_std_list
{
    static const bool value = false;
};

template <typename T>
struct is_std_list<std::list<T>>
{
    static const bool value = true;
};

template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
std::string print_ip(T &&input)
{
    std::string result;
    const size_t count_bytes = sizeof(input);
    for (size_t i = count_bytes - 1; i > 0; --i)
    {
        result += std::to_string(uint8_t(input >> i * 8) & 0xFF) + ".";
    }

    result += std::to_string(uint8_t(input) & 0xFF);

    return result;
}

template <typename T, std::enable_if_t<std::is_same<T, std::string>::value, bool> = true>
T print_ip(T &&input)
{
    return input;
}

template <typename T>
std::string out_from_std(T &&input)
{
    std::stringstream result;

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        result << *it << ".";
    }

    auto ret = result.str();
    ret.pop_back();

    return ret;
}

template <typename T, std::enable_if_t<is_std_vector<T>::value, bool> = true>
std::string print_ip(T &&input)
{
    return out_from_std(std::forward<T>(input));
}

template <typename T, std::enable_if_t<is_std_list<T>::value, bool> = true>
std::string print_ip(T &&input)
{
    return out_from_std(std::forward<T>(input));
}

template <typename T, size_t n = std::tuple_size<T>::value - 1>
struct check_tuple
{
    static constexpr bool value = check_tuple<T, n - 1>::value && check_tuple<T, n - 2>::value;
};

template <typename T>
struct check_tuple<T, 0>
{
    static constexpr bool value = std::is_same<std::tuple_element_t<0, T>, std::tuple_element_t<1, T>>::value;
};

template <typename T>
struct check_tuple<T, 1>
{
    static constexpr bool value = check_tuple<T, 0>::value && std::is_same<std::tuple_element_t<1, T>, std::tuple_element_t<2, T>>::value;
};

template <typename T, std::enable_if_t<check_tuple<T>::value, bool> = true>
std::string print_ip(T &&input)
{
    std::stringstream sstr;

    print(sstr, input);

    auto str = sstr.str();
    str.pop_back();
    return str;
}