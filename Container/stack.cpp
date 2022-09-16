#include <iostream>
#include <stack>
#include <deque>
#include <map>
#include <vector>

void memberf()
{
    std::stack<int> c;
    c.push(5);
    std::cout << c.size() << std::endl;

    std::stack<int> c2(c);
    std::cout << c.size() << std::endl;

    std::deque<int> d{ 1,2,3};
    std::stack<int> c3(d);
    std::cout << c3.size() << std::endl;

    const auto a = {1,2,3};
    std::stack<int> cd(a);
    std::cout << cd.size() << std::endl;


    std::deque<int> da {1,23,5};
    std::deque<int> db {1,23,5};
    std::stack<int> ba;
    std::stack<int> bb;
    ba.push(1);
    db = da;
    db = std::move(da);

    bb = ba;
    bb = std::move(ba);

}
auto printSsizetop = [](std::stack<int>& s)
{
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;

};
void elementAccss()
{
    std::stack<int> a;
    a.push(2);
    a.push(27);
    a.push(25);
    printSsizetop(a);
    a.pop();
    printSsizetop(a);

}

struct S
{
    int i;
    S(int k, double d, std::string s) : i{k}
    {
        std::cout << k << " " << d << " " << s << std::endl;
    }
};
void moditifiers()
{
    std::stack<S> ss;
    const S& s = ss.emplace(1,1,"C");
    std::cout << "i " <<  s.i ;

}

template<typename T>
void print(T t)
{
    std::cout << t.size() << std::endl;
    for(; !t.empty() ; t.pop())
        std::cout << t.top() << " ";
    std::cout << std::endl;

}
void swasstacks()
{
    std::vector<int> a{1,2,3}, b{9,8,7};
    std::stack asa {std::move(a)};
    std::stack asb {std::move(b)};

    print(asa);
    print(asb);

    asa.swap(asb);

    print(asa);
    print(asb);
}
int main()
{


}