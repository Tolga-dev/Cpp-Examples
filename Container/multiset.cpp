#include <iostream>
#include <set>

void print(const std::multiset<int>& ms)
{
    for(auto i : ms)
        std::cout<< i << " ";
    std::cout << std::endl;
}
void memf()
{
    std::multiset<int> a;
    a.insert(1);
    a.insert(21);
    a.insert(13);
    a.insert(17);
    a.insert(17);

    std::multiset<int> b(a.begin() , a.end());
    print(b);

    std::multiset<int> c(a);
    print(c);

    std::multiset<int> d(std::move(a));

    std::multiset<int> f = a;
}

void iterator()
{
    std::multiset<int> a = {
            1,
            2,
            3,
            5,
            3
    };

    for(auto it = a.begin(); it != a.end();)
    {
        auto cnt = a.count(*it);
        std::cout << cnt << " " << *it << std::endl;
        std::advance(it, cnt);
    }
    for(auto it = a.crbegin(); it != a.crend();)
    {
        auto cnt = a.count(*it);
        std::cout << cnt << " " << *it << std::endl;
        std::advance(it, cnt);
    }
}
void moditifiers()
{
    std::multiset<int> con {1,2,3};

    auto printlam = [](const int& n){ std::cout << " " << n; };
    auto printlamsreach = [&](std::multiset<int> cox)
    {
        for(auto i : cox)
            if(con.contains(i))
                std::cout<< "yeas";
            else
                std::cout<< "no";

    };

    con.insert(2);
    con.emplace(2);

    auto it = con.emplace_hint(con.begin() , 12);
    it = con.emplace_hint(it , 31);
    con.emplace_hint(it, 310);
    //con.erase(2);
//    auto ret = con.equal_range(2);
    //con.erase(ret.first, ret.second);
    auto ret = con.upper_bound(13);
    std::cout << *ret << std::endl;


    std::for_each(con.begin(), con.end(), printlam);
    printlamsreach({11});

}

int main()
{
    
    return 0;
}