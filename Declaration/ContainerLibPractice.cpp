#include <iostream>
#include <array>

struct SpecialArrayCase
{

    static void f(std::array<int, 1> arr)
    {
        if(arr.end() == arr.begin())
            std::cout << "Special!" << std::endl;
        else
        {
            for(int i = 0; i < arr.size(); i++)
                std::cout << arr[i] << std::endl;

        }
    }
};
void arraySpecialCase()
{
    std::array<int , 1> a = {1};
    SpecialArrayCase::f(a);
};

// elements at
struct elementArray
{
    std::array<long long , 2> b;
    elementArray(std::array<long long , 2> Element) : b(Element) {}

    void elementAr(std::array<long long , 2> b)
    {
        std::cout << b.at(1) << std::endl;
        std::cout << b.front() << std::endl;
        std::cout << *b.begin() << std::endl;
        std::cout << b.back() << std::endl;
        std::cout << *b.end() << std::endl;
        std::cout << b.size() << std::endl;
        try{
            b.at(6) = 5;
        }
        catch (std::out_of_range const& exc)
        {
            std::cout << exc.what() << std::endl;
        }
        pointer_f(b.data(), b.size());
    }
    static void pointer_f(const long long* p, std::size_t size)
    {
        std::cout <<p<<std::endl;
        for(std::size_t i=0; i < size; i++)
            std::cout << &p[i] <<std::endl;
    }
    void UsageOfBeginFunction(std::array<long long , 2> b)
    {
        std::cout << *b.begin() << " " <<*b.cbegin() << std::endl;
        std::cout << *b.end() << " " <<*b.cend() << std::endl;
    }
    void ReverseFUnctionREndRbegin(std::array<long long , 2> b)
    {
        std::cout << b.crbegin()[0] << std::endl;
        std::cout << b.crend()[0] << std::endl;
    }
    void ReverseFUnctionREnd(std::array<int, 11> a)
    {
        std::for_each(a.crbegin(), a.crend(), [](int e){ std::cout << e << ' '; });
        std::for_each(a.begin(), a.end(), [](int e){ std::cout << e << ' '; });
    }
    void wgetF(std::array<long long , 2> a)
    {

        std::cout <<" you get : " <<std::get<1>(a) << std::endl;
    }
    void toarrayfunc()
    {
        auto a = std::to_array("foo");
        auto b = std::to_array({111,23,132,21,32});
        auto a4 = std::to_array<std::pair<int, float>>(
                { { 3, .0f }, { 4, .1f }, { 4, .1e23f } });
        std::cout << a4.size() << std::endl;
    }

    template<class T>
    void tuplesize(T)
    {
            int a[std::tuple_size<T>::value];
            std::cout << std::size(a);
    }


};
void elementsFunction()
{
    std::array<long long , 2> b = {1,2};
    std::array<long long , 2> bv = {5,5};
    std::array<long long , 4> bX = {15,5,6,463};
    std::array<long long , 0> bx; // empty
    std::cout<< bx.empty() << std::endl;
    elementArray elementArray(b);
    elementArray.elementAr(b);
    elementArray.UsageOfBeginFunction(b);
    elementArray.ReverseFUnctionREndRbegin(b);

    std::array<int, 11> a {1, 11, 11, 35, 0, 12, 79, 76, 76, 69, 40};
    elementArray.ReverseFUnctionREnd(a);
    std::cout<<"size: " <<b.size() << std::endl;
    std::cout<<"size: " <<b.max_size() << std::endl;

    std::array<int , 5> as = {1,2,3,4};
    as.fill(1);
//    std::cout << a[3] << std::endl;

    std::array<int , 6> ab = {11,2,32,13,51165,1};
    std::array<int , 6> bb;
    bb.swap(ab);
    std::cout<< bb[0];

    std::swap(bv, b);
    elementArray.wgetF(b);

    std::array<int , 465>arrs;
    elementArray.tuplesize(arrs);

}

int main()
{
   elementsFunction();





}
