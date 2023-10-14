#include <iostream>
#include <string_view>
#include <limits.h>
#include <memory>
#include <vector>
#include <functional>
#include <vector>
#include <memory>


/*
void Undefined(int argc, char **argv)
{
    // g++ UBsan.cpp -o rule -Wall -fsanitize=undefined
// g++ UBsan.cpp -o rule -Wall -fsanitize=signed-integer-overflow,null,alignment -fno-sanitize-recover=null -fsanitize-trap=alignment
    int k = 0x7fffffff;
    k += argc;

}
int overflow(int argc, char **argv) {
// g++ UBsan.cpp -o rule -Wall -fsanitize=undefined

    int arr[argc];

    return arr[-1];

}
int insufficientSpace()
{
//g++ UBsan.cpp -o rule -Wall  -fno-omit-frame-pointer -fsanitize=undefined
    int *p = (int*) malloc(20 * sizeof(int));
    int i = p[24524];
    p[21] = i;

    return 0;
}

int overflowInt(int argc, char **argv) {
// g++ UBsan.cpp -o rule -fsanitize=undefined
    unsigned int i;
    i = INT_MAX + argc; // integer overflow

    return i;
}


class UBNullPtr
{
public:
    int member() {
        return this == nullptr ? 1 : 0; // cannot be nullptr
    }
    int get_val(int &t)
    {
        return &t == nullptr ? 1 : 0;
    }
};
void classUB()
{
    UBNullPtr ub;
    int a = 31;
    std::cout << ub.member() << std::endl;
    std::cout << ub.get_val(a) << std::endl;
}

enum class UnreachableEnum
{
        val1,
        val2,
        val3
};

std::string_view  get_name(UnreachableEnum anEnum)
{
    switch (anEnum) { // val3 not handled
        case UnreachableEnum::val1: return "0";
        case UnreachableEnum::val2: return "1";
    }
    return "3";

}
 */
////////// scoped enums
/*
enum class Choices {
    option1
};
enum class OtherChoices {
    option2
};
int foo() {
 //   int val = option1; // cannot compile, need scope
 //   int val2 = Choices::option1; // cannot compile, wrong type
    Choices val = Choices::option1; // compiles
//    val = OtherChoices::option2; // cannot compile, wrong type

    return 0;
}
*/
/////////////////Prefer if constexpr over SFINAE
///atladim ciddi usendim
/*
void f()
{

    if constexpr(true) {}
    else{}
}
 */
///////////// constrain templates

template<typename T, typename P>
auto divide(T num, P num2)
{
    std::cout << "Case1" << std::endl;
    if constexpr(std::is_integral_v<T> &&
                 std::is_integral_v<P>)
    {
        return num2 == 0 ?
            throw std::runtime_error(" cant divide by 0! ") :
            num / num2;
    }
    else
        throw std::runtime_error(" not dividable value! ");
}
// REQUIRES EVENT CONCEPT
template<typename T, typename P>
auto divide(T num, P num2) requires
        (   std::is_integral_v<T> &&
            std::is_integral_v<P>)
{
    std::cout << "Case2" << std::endl;
    return num2 == 0 ?
           throw std::runtime_error(" cant divide by 0! ") :
           num / num2;
}
// C++20 AUTO CONCEPT SAME

auto divide(std::integral auto num, std::integral auto num2)
{
    std::cout << "Case3" << std::endl;
    return num2 == 0 ?
           throw std::runtime_error(" cant divide by 0! ") :
           num / num2;
}

template<typename T> concept integral = std::is_integral_v<T>;

template<typename P>
auto Integral(P num1) requires ( integral<P>)
{
    std::cout << " Case 1 " <<std::endl;

    return num1;
}

auto Integral(const integral auto val1, const integral auto val2)
{
    std::cout << " Case 2 " <<std::endl;

    return val1 + val2;
}
// requires requires

template<typename T> requires requires(T a, T b) {a+b;}
auto add(T a, T b)
{
    return a + b;
}
void bar()
{
    long long a = 565;
    int b = 5;
    float af = 565;
    int bi = 5;

    integral auto const val = Integral(4,5);

//    Integral(af); // not satify
    Integral(b);

//    divide(a,b);
//    divide(af,bi);
//    Case2
//    Case1
//    terminate called after throwing an instance of 'std::runtime_error'
//    what():   not dividable value!

}

/////// Lippincott Functions
/*
void Lippincott()
{
    try { throw;}
    catch (const std::runtime_error &) {}
    catch (const std::exception &) {}
}
int b1(){ return 0;}
int b2(){ return 0;}
void f1()
{
    try{ b1(); }
    catch(...) { Lippincott();}
}
void f2()
{
    try{ b2(); }
    catch(...) { Lippincott();}
}
///////[[nodiscard]]
/*
template<typename T> concept integral = std::is_integral_v<T>;

template<typename P>
[[nodiscard(" ignoring this result leaks resources")]] auto get(P num) requires(integral<P>)
{
    std::cout << " case 1 " << std::endl;
   // return num == 0 ? throw std::runtime_error(" ignored result ") : num;
};

[[nodiscard(" ignoring this result causes unexpected results")]] int get(auto num)
{
    std::cout << " case 2 " << std::endl;
    return num == 0 ? throw std::runtime_error(" ignored result ") : num;
};
int voidMe()
{
    double a = 5.5;
    return get(a);
}
*/
///////////////////// dont return raw pointers
/*
int *get_val();

auto a()
{
    return (*get_val() == NULL ? 0 : 1);
}
 */
///////////////////stack over heap
auto StackAllocation()
{
//    int bar[3];
//    std::string foo = "Hello World!";
}

auto HeapAllocation()
{
    int *ptr = new int[10];
    ptr[0] = 1;
    std::cout << ptr[0] << std::endl;
}
/// bad
auto _string()
{
    return std::make_unique<std::string>("Hello World!");
}

//////////////////// std::function
/*
auto f(const int& num)
{
    std::cout << " by " << num << std::endl;
}
void f2_k(const std::string& num)
{
    std::cout << " by " << num << std::endl;
}

template<typename T>
std::function<T()> function()
{
    std::function<void()> lambda_f = []() { f(2); };
    return lambda_f;
}

template<typename T>
std::function<T()> function2(int arr)
{
    std::function<void()> lambda_f = [&]() { f(arr); };
    return lambda_f;
}

template<class T>
struct bar
{
    bar(int n) : n_(n) {}
    void print(int i) const { std::cout << n_ << std::endl;}
    void print2(const std::string& s) const { std::cout << s << std::endl;}
    int n_;
};
class num
{
public:
    void operator()(int i ) const { std::cout << i << std::endl; }

};
void bk()
{
    std::string string("Temp");

    std::function<void(const int& num)> display_f1 = f;
    display_f1(31);

    auto lambda_f2 = function<void>();
    lambda_f2();

    auto lambda_f1 = function2<void>(5);
    lambda_f1();

    std::function<void()> lambda_f = []() { f(2); };
    lambda_f();

    std::function<void()> bind_f = std::bind(f,31);
    bind_f();
    std::function<void()> bind_l = [] { return f(31); };
    bind_l();


    std::function<void(const bar<int>&, int)> f_display = &bar<int>::print;
    const bar<int> b(56);
    f_display(b,2654);
    f_display(3,253);

    std::function<int(bar<int> const& )> f_accessor = &bar<int>::n_;
    std::cout << " num : " << f_accessor(b) << std::endl;

    std::function<void(int)> f_add_display = std::bind( &bar<int>::print, b, std::placeholders::_1);
    f_add_display(33);

    std::function<void(int)> f_add_1 = num();
    f_add_1(12);

//        std::function<void(int)> display_f;
//        display_f(31);  // bad_function_call

}
void bk2()
{

    const bar<int> ins(1);
    std::string string("hi");

    std::function<void(const std::string&)> f_dis = std::bind(&bar<int>::print2, ins, std::placeholders::_1);
    f_dis(string);

//    f_dis = std::bind(&f2_k,std::placeholders::_1);
    f_dis = [](auto && PH1) { return f2_k(std::forward<decltype(PH1)>(PH1)); };
    f_dis(string);


    auto lambda = [](std::string pre, char o, int rep, std::string post) {
        std::cout << pre;
        while (rep-- > 0) std::cout << o;
        std::cout << post << '\n';
    };
    std::function<void(std::string, char, int, std::string)> g =
            std::bind(&decltype(lambda)::operator(),&lambda,
                      std::placeholders::_1,
                      std::placeholders::_2,
                      std::placeholders::_3,
                      std::placeholders::_4
            );

    g("G", 'o', 'o'-'g', "gol");

}
 */
//////////////////// std::bind
/*
void fl(int n, int n1, int n2, int n3, int n5)
{
    std::cout << n << ' '<< n1 << ' ' << n2 << ' ' << n3 << ' ' << n5 << '\n';
}
auto gl(int n)
{
    return n;
}
void bk6()
{
    using  namespace std::placeholders;

    int n = 5;
    std::function<void(int,int,int,int,int)> l  = std::bind(&fl,_1,45,_2,5,n);
    l(1,2,3,4,5);

    std::function<void(int,int)> l1  = std::bind(&fl,_1,std::bind(gl,5),_2,5,n);
    l1(1,2);

}
 */

/////////////////////dont use init list for non trivial

/// unique pointer
/*
struct f
{
    virtual ~f() = default;
    virtual void bar(){ std::cout << "f::bar" << std::endl; }
};
struct d : f
{
    d() { std::cout << " D::D" << std::endl;}
    ~d() { std::cout << " D::~D" << std::endl;}

    void bar() override { std::cout << "D::Bar" << std::endl;}

};
std::unique_ptr<d> pass(std::unique_ptr<d> p)
{
    p->bar();
    return p;
}
void p()
{
    {
        std::unique_ptr<d> p = std::make_unique<d>();
        std::unique_ptr<d> q = pass(std::move(p));
    }
    {
        std::unique_ptr<f> p = std::make_unique<d>();
        p->bar();
    }

}
 */
/// shared ptr
/*
struct base
{
    base() { std::cout << " base::base() " << std::endl;}
    ~base() { std::cout << " base::~base() " << std::endl;}
};
struct derived : base
{
    derived() { std::cout << " derived::derived()" << std::endl;}
    ~derived() { std::cout << " derived::~derived()" << std::endl;}
};
void p2()
{
    {
        std::shared_ptr<base> p = std::make_shared<derived>();
        {
            std::shared_ptr<base> p1 = p;
            std::shared_ptr<base> p2 = p1;
            std::cout << p.use_count() << std::endl;
            std::cout << p.get() << std::endl;
            std::cout << p1.get() << std::endl;
            std::cout << p2.get() << std::endl;
        }
        std::cout << p.use_count() << std::endl;

    }
}
*/

std::vector<std::shared_ptr<int>> data{
        std::make_unique<int>(40), std::make_unique<int>(2)
};
std::array<std::shared_ptr<int>, 2> data2{
        std::make_shared<int>(40), std::make_shared<int>(2)
};

std::vector<int> vec{0,1};
std::vector<int, std::allocator<int> > m = std::vector<int, std::allocator<int> >
        {std::initializer_list<int>{1,0}, std::allocator<int>()};

/*
auto f(int i, int j, int k ) {
    return std::initializer_list<int>{ i, j, k};
}
void px()
{
    for (int i : f(1,2,3)) {
        std::cout << i << " ";
    }
}
*/
//std::vector vec{std::make_shared<int>(1), std::make_shared<int>(2)};

//////////////////////// test tools

//std::size_t find(const char *str, const size_t size)
//{
//    std::size_t loc = 0;
//
//    while(str[loc] != '\n')
//    {
//        ++loc;
//    }
//
//    return  loc;
//}
//
//extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, std::size_t Size) {
//     find(reinterpret_cast<const char *>(Data), Size);
//    return 0;  // Values other than 0 and -1 are reserved for future use.
//
//}

//extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
//    if (size > 0 && data[0] == 'H')
//        if (size > 1 && data[1] == 'I')
//            if (size > 2 && data[2] == '!')
//                __builtin_trap();
//    return 0;
//}
///////////////// default comparison <=>

struct cont
{
    int id;

    friend auto operator <=>(const cont& M, const cont& N) = default;
};
void defaultOperator()
{
    cont c,d;
    c.id = 1;
    d.id = 2;


    std::cout <<std::boolalpha<< (c < d) << std::endl;
    std::cout << (c == d) << std::endl;
    std::cout << (c >= d) << std::endl;
    std::cout << (c <= d) << std::endl;

}
/////////// consteval continit

/*
consteval void foo(); // must at compile time
constexpr void bar(); // may at compile time
constinit int b; // not based on local
static constinit int l;
//    consteval int x = 5;  based on functions
//    constinit int b; // not based on local
constexpr int f = 5;
*/
/*
consteval int get(int i)
{
    return i * 42;
}

constexpr int faa(int i)
{
    if consteval{
        return get(i);
    }
    else
    {
        return 24;
    }
}
void baa()
{
    constexpr auto v = faa(1);

//    constexpr auto v1 = faa();
//    const auto v2 = faa();
}
*/
/////////////////// direct initialization

struct Data
{
    std::string f;
    std::string s;

};
void direcct()
{
    Data d{.f = "f", .s = "s"};
    Data d1 = {"f","s"};

    std::cout << d1.f << std::endl;
    std::cout << d1.s << std::endl;

}
////////////////////// lambda
void Examples()
{
    []{};
    [](){};

    []() constexpr -> int { return 31;};

    int i = 5;
    [i](){ return i + 42; };


    [i = 42]{ return i + 42;};
}
/// forward decltype later
/////////////////// valgrind

void f(void)
{
    char * q = new char[31];

}

int fx() {
    f();
    std::cout << " hello world !" << std::endl;
//    g++ main.cpp -o main
//    valgrind --leak-check=full ./main
}
//////////////////////// heaptrack
// g++ main.cpp -o main
// heaptrack ./main
void fa(void)
{
    for (int i = 0; i <100 ; ++i) {
        auto k = new int();
    }

}



int main() {



}

