#include <cstdint>
#include <type_traits>
#include <tuple>

template<class Tuple, std::size_t N>
struct TuplePrinter
{
    static void print(std::stringstream& sstream, const Tuple& t)
    {
        TuplePrinter<Tuple, N - 1>::print(sstream, t);
        sstream << std::get<N-1>(t) << ".";
    }
};
 
template<class Tuple>
struct TuplePrinter<Tuple, 1>
{
    static void print(std::stringstream& sstream, const Tuple& t)
    {
        sstream << std::get<0>(t) << ".";
    }
};
 
template<typename... Args, std::enable_if_t<sizeof...(Args) == 0, int> = 0>
void print(std::stringstream& sstream, const std::tuple<Args...>& t)
{
    
}
 
template<typename... Args, std::enable_if_t<sizeof...(Args) != 0, int> = 0>
void print(std::stringstream& sstream, const std::tuple<Args...>& t)
{
    TuplePrinter<decltype(t), sizeof...(Args)>::print(sstream, t);
}