#include <iostream>
#include <span>
#include <array>
#include <cstddef>
#include <iomanip>


void dynamic()
{
    auto print = [](std::size_t ex){
        std::cout<< std::dynamic_extent << std::endl;
        std::cout<< ex << std::endl;
        if(ex == std::dynamic_extent)
            std::cout << "dynamic!";
        else
            std::cout << "extent!";
        std::cout<<std::endl;
    };

    int a[]{1,2,3};
    std::span s = {a};
    print(s.extent);

    std::array ar{1,2,3,4,5};
    std::span<int, std::dynamic_extent> sx = {ar};
    print(sx.extent);

}

void print(std::span<const int> sp)
{

    if(sp.empty())
        throw "empty";
    for(auto it = sp.begin(); it != sp.end(); ++it)
        std::cout<< *it << " ";
    std::cout << '\n';
    std::cout<< sp.front() << " ";
    std::cout<< sp.back() << " ";
    std::cout<< sp[0] << " ";
    auto spx = sp.data();
    std::cout<< spx[0] << " ";


}
void iteratorselementaccess()
{
    int array[] {1,123,21};
    print(array);
}
void subwiews()
{
    auto prints = []( std::span<const int> s)
    {
        std::cout << s.size() << std::endl;
        std::cout << sizeof(s) << std::endl;
        std::cout << s.size_bytes() << std::endl;

        std::cout << s.first(7).size() << std::endl;
        std::cout << s.first<6>().size() << std::endl;
        std::cout << s.last<5>().size() << std::endl;
        std::cout << s.last(4).size() << std::endl;
        std::cout << s.subspan(2,3).size() << std::endl;
        std::cout << s.subspan<3,2>().size() << std::endl;

    };

    int arr[] {654,654,654,654,654,6};
    prints(arr);
}

void nonmember()
{
    float mydata[]{3.141592f};
    auto const cb = std::as_bytes(std::span{mydata});

    for(auto const i : cb)
        std::cout << std::to_integer<int>(i) << " ";

}

int main()
{



}