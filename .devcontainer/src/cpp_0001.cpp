#include <iostream>
#include <string>
#include <utility>
#include <string_view>
#include <compare>
#include <set>
#include <tuple>
#include <typeinfo>

#include<cxxabi.h>

template<typename test>
struct strct{
    using type = test;
    explicit strct(type value_1, type value_2):value_1_(value_1), value_2_(value_2) {}
    void set_value(type value_1, type value_2)
    {
        value_1_ = std::move(value_1);
        value_2_ = std::move(value_2); 
    }

    decltype(auto) get_value()
    {
        return std::tuple{value_1_, value_2_};
    }
    auto operator <=>(const strct& other) const = default;

    // need strict<T> as operator <<  is not member function
    template< class T>
    friend std::ostream& operator<<(std::ostream& os, const strct<T>& str);

    private:
    type value_1_{};
    type value_2_{};
};

template<typename test>
std::ostream& operator<<(std::ostream& os, const strct<test>& str)
{
    int status = 0;
    os << "[ overloaded operator value_1: " << str.value_1_ <<" ]";
    os << "[ overloaded operator: value_2 " << str.value_2_ <<" ]\n";
    os << "  size of : [" << abi::__cxa_demangle(typeid(test).name(),0 ,0,&status )<< "] " << sizeof(decltype(std::declval<test>())) << "\n";
    return os;

}

int main()
{
    strct/*<const char*>*/ tmplt_test_char("test const char* 1", "test const char* 2");                // const char* is deduced by default
    std::cout<< tmplt_test_char;

    strct <std::string>  tmplt_test_string("test string 1", "test string 2");                          // specify template parameter to specify desired deduction other than default deduction
    std::cout<< tmplt_test_string;

    strct <std::string_view>  tmplt_test_string_view("test string_view 1", "test string_view 2");      // specify template parameter to specify desired deduction other than default deduction
    std::cout<< tmplt_test_string_view;

    // C++20 spaceship operator
    strct test_1(0, 1);
    strct test_2(1, 2);
    std::cout << std::boolalpha;
    std::cout << (test_1 <=test_2) << "\n";
    std::cout<< std::noboolalpha;

    std::set<strct<int>> tests{strct(0,1), strct(1,2), strct(2,3), strct(3,4), strct(4,5), strct(5,6)};

    for(auto value:tests) std::cout<< value<<"\n";
    std::cout<< sizeof(int) << "\n";
}