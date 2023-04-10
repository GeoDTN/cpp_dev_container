#include <iostream>
#include <string>
#include <utility>
#include <string_view>
#include <compare>
#include <set>

template<typename test>
struct strct{
    using type = test;
    explicit strct(type value):value_(value){}
    void set_value(type value)
    {
        value_ = std::move(value); 
    }

    type get_value()
    {
        return value_;
    }
    auto operator <=>(const strct& other) const = default;

    // need strict<T> as operator <<  is not member function
    template< class T>
    friend std::ostream& operator<<(std::ostream& os, const strct<T>& str);

    private:
    type value_{};
};

template<typename test>
std::ostream& operator<<(std::ostream& os, const strct<test>& str)
{
    os << "[ overloaded operator: " << str.value_ <<" ]";
    os << "  size of value_ : [" << sizeof(str.value_) << "]\n";
    return os;

}

int main()
{
    strct/*<const char*>*/ tmplt_test_char("test const char*");                // const char* is deduced by default
    std::cout<< tmplt_test_char;

    strct <std::string>  tmplt_test_string("test string");                     // specify template parameter to specify desired deduction other than default deduction
    std::cout<< tmplt_test_string;

    strct <std::string_view>  tmplt_test_string_view("test string_view");      // specify template parameter to specify desired deduction other than default deduction
    std::cout<< tmplt_test_string_view;

    // C++20 spaceship operator
    strct test_1(0);
    strct test_2(1);
    std::cout << std::boolalpha;
    std::cout << (test_1 <=test_2) << "\n";
    std::cout<< std::noboolalpha;

    std::set<strct<int>> tests{strct(1), strct(2), strct(3), strct(4), strct(5), strct(6)};

    for(auto value:tests) std::cout<< value<<"\n";

}