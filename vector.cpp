#include <iostream>
#include <vector>


struct VectorMy
{

    static void f()
    {
        std::vector<int> v{ 1, 5 , 9, 7}, c{2,6,10,8};
        v.push_back(26);
        v.push_back(13);

        v.swap(c);

        for(int i : v)
            std::cout << i << std::endl;

        v.clear();

        for(int i : v)
            std::cout << i << std::endl;
        std::cout << v.size() << std::endl;

        v = c;

        for(int i : v)
            std::cout << i << std::endl;
        std::cout << v.size() << std::endl;

        v.assign(v.size(), 'b');

        for(int i : v)
            std::cout << i << std::endl;

    }
};


int main()
{
    VectorMy::f();


}