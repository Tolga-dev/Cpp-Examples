#include <iostream>
#include <list>

int main()
{

    std::list<int> list1;
    auto printlist  = [&]()
    {
        for (char c : list1)
            std::cout << c << ' ';
        std::cout << '\n';
        std::cout << list1.front() <<'\n';
        std::cout << list1.back() <<'\n';

    };
    list1.assign(3, 'a');

    list1.insert(list1.begin(), 20);

    list1.erase(list1.begin());


    printlist();


    return 0;
}